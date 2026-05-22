#include <iostream>
#include <iomanip>
#include <string> // 
#include <limits> //

using namespace std;

struct Book {
    string title;
    string author;
    bool available;
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int bookCount = 0;

// Add Book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }
    
    Book newBook;
    
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    
    cout << "Enter author: ";
    getline(cin, newBook.author);

    int availInput;
    cout << "Is the book available? (1=Yes, 0=No): ";
    cin >> availInput;
    

    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        newBook.available = true; 
        cout << "Invalid input. Defaulting to Available (Yes).\n";
    } else {
        newBook.available = (availInput == 1);
    }

    library[bookCount++] = newBook;
    cout << "Book added successfully!\n";
}

// Search Book
void searchBook() {
    cin.ignore();
    string keyword;
    cout << "Enter title or author to search: ";
    getline(cin, keyword);

    bool found = false;
    cout << "\n--- Search Results ---\n";
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title.find(keyword) != string::npos || 
            library[i].author.find(keyword) != string::npos) {
            
            cout << "Found: " << library[i].title << " by " << library[i].author
                 << " - " << (library[i].available ? "Available" : "Not Available") << endl;
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

// Update Availability
void updateAvailability() {
    cin.ignore();
    string title;
    cout << "Enter the EXACT book title to update: ";
    getline(cin, title);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == title) {
            cout << "Current status: " << (library[i].available ? "Available" : "Not Available") << endl;
            
            int availInput;
            cout << "Enter new status (1=Available, 0=Not Available): ";
            cin >> availInput;
            
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Update cancelled.\n";
            } else {
                library[i].available = (availInput == 1);
                cout << "Availability updated!\n";
            }
            return;
        }
    }
    cout << "Book not found (Ensure you typed the exact title).\n";
}

// Delete Book
void deleteBook() {
    cin.ignore();
    string title;
    cout << "Enter the EXACT book title to delete: ";
    getline(cin, title);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == title) {
            // Shift Logic
            for (int j = i; j < bookCount-1; j++) {
                library[j] = library[j+1];
            }
            bookCount--;
            cout << "Book deleted.\n";
            return;
        }
    }
    cout << "Book not found (Ensure you typed the exact title).\n";
}

// Display Inventory
void displayInventory() {
    if (bookCount == 0) {
        cout << "Library is empty.\n";
        return;
    }
    cout << "\n--- Library Inventory ---\n";
    cout << left << setw(5) << "No." << setw(25) << "Title" << setw(20) << "Author" << "Status" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    for (int i = 0; i < bookCount; i++) {
        cout << left << setw(5) << i+1 
             << setw(25) << library[i].title 
             << setw(20) << library[i].author 
             << (library[i].available ? "Available" : "Not Available") << endl;
    }
}

// Main Program
int main() {
    int choice;
    do {
        cout << "\n--- Library Inventory System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Update Availability\n";
        cout << "4. Delete Book\n";
        cout << "5. Display Inventory\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a number.\n";
            continue; 
        }

        switch(choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: updateAvailability(); break;
            case 4: deleteBook(); break;
            case 5: displayInventory(); break;
            case 6: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}