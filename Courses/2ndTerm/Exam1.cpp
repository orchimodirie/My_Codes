//Abenoja TS01 - Question 1
#include <iostream>
#include <string>

using namespace std;

// struct to represent a single node in the linked list
struct Node {
    string name;
    string mobileNumber;
    Node* next;

    // constructor to easily initialize a new node
    Node(string n, string m) {
        name = n;
        mobileNumber = m;
        next = nullptr;
    }
};

// Class for managing the contact list using encapsulation
class ContactList {
private:
    Node* head; // Pointer to the start of the list

public:
    // Constructor initializes an empty list
    ContactList() {
        head = nullptr;
    }

    // Destructor to free memory when the program ends
    ~ContactList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function for adding contanct in the list
    void addContact(string name, string mobileNumber) {
        Node* newNode = new Node(name, mobileNumber);

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            cout << "Contact added successfully!\n";
            return;
        }

        // Traverse to the end of the list
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Link the last node to the new node
        temp->next = newNode;
        cout << "Contact added successfully!\n";
    }

    // Function to display all contacts
    void displayContacts() {
        if (head == nullptr) {
            cout << "The contact list is empty.\n";
            return;
        }

        cout << "\n--- Contact List ---\n";
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << " | Mobile: " << temp->mobileNumber << "\n";
            temp = temp->next;
        }
        cout << "--------------------\n";
    }

    // Function to delete a contact by name
    void deleteContact(string targetName) {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete.\n";
            return;
        }

       
        if (head->name == targetName) {
            Node* temp = head;
            head = head->next; // Move head to the second node
            delete temp;       // Free memory
            cout << "Contact '" << targetName << "' deleted successfully.\n";
            return;
        }

        //The contact is somewhere else in the list
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->name != targetName) {
            previous = current;
            current = current->next;
        }

        // If the contact wasn't found
        if (current == nullptr) {
            cout << "Contact '" << targetName << "' not found.\n";
            return;
        }

        // Unlink the node and delete it
        previous->next = current->next;
        delete current;
        cout << "Contact '" << targetName << "' deleted successfully.\n";
    }

    // counting the total number of nodes
    void countContacts() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total contacts saved: " << count << "\n";
    }

    // sorting contact alphabetically
    void sortContacts() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Not enough contacts to sort.\n";
            return;
        }

        //  Bubble Sort to swap data 
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->name > j->name) {
                    // Swap names
                    string tempName = i->name;
                    i->name = j->name;
                    j->name = tempName;

                    // Swap mobile numbers
                    string tempMobile = i->mobileNumber;
                    i->mobileNumber = j->mobileNumber;
                    j->mobileNumber = tempMobile;
                }
            }
        }
        cout << "Contact list sorted alphabetically!\n";
    }
};

int main() {
    ContactList myContacts;
    int choice;
    string name, mobile;

    do {
        cout << "\n=== Contact Book Menu ===\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Delete a Contact\n";
        cout << "4. Count Contacts\n";
        cout << "5. Sort Contacts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        
        // input validation for possible errors
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                
                cout << "Enter name: ";
                cin >> ws; 
                getline(cin, name);
                cout << "Enter mobile number: ";
                getline(cin, mobile);
                myContacts.addContact(name, mobile);
                break;
            case 2:
                myContacts.displayContacts();
                break;
            case 3:
                cout << "Enter the name of the contact to delete: ";
                cin >> ws;
                getline(cin, name);
                myContacts.deleteContact(name);
                break;
            case 4:
                myContacts.countContacts();
                break;
            case 5:
                myContacts.sortContacts();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}