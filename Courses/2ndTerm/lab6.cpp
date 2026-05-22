#include <iostream>
#include <string>

using namespace std;

struct Player {
    string nickname;
    int age;
    double score1;
    double score2;
};


struct Node {
    Player player;
    Node* next;
};

Node* head = nullptr;

void addRecord(const Player& player) {
    Node* newNode = new Node;
    newNode->player = player;
    newNode->next = head;
    head = newNode;
}


void viewRecords() {
    Node* current = head;
    
    if (current == nullptr) {
        cout << "No records to display." << endl;
        return;
    }
    
    while (current != nullptr) {
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Age: " << current->player.age << endl;
        cout << "Score 1: " << current->player.score1 << endl;
        cout << "Score 2: " << current->player.score2 << endl;
        cout << "--------------------" << endl;
        current = current->next;
    }
}

void computeAverage() {
    Node* current = head;
    
    if (current == nullptr) {
        cout << "No records to calculate." << endl;
        return;
    }
    
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Average Score: " << average << endl;
        cout << "--------------------" << endl;
        current = current->next;
    }
}


void showMaxAverage() {
    Node* current = head;
    if (current == nullptr) {
        cout << "No records available." << endl;
        return;
    }

    double maxAverage = -1; 
    
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average > maxAverage) {
            maxAverage = average;
        }
        current = current->next;
    }
    
    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == maxAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "--------------------" << endl;
        }
        current = current->next;
    }
}


void showMinAverage() {
    Node* current = head;
    if (current == nullptr) {
        cout << "No records available." << endl;
        return;
    }

    double minAverage = 999999; 
    
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average < minAverage) {
            minAverage = average;
        }
        current = current->next;
    }
    
    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "--------------------" << endl;
        }
        current = current->next;
    }
}
int main() {
    int choice;
    
    do {
        cout << "\nPlayer Records Management" << endl;
        cout << "[1] Add Record" << endl;
        cout << "[2] View Records" << endl;
        cout << "[3] Compute Average" << endl;
        cout << "[4] Show Max Average" << endl;
        cout << "[5] Show Min Average" << endl;
        cout << "[6] Exit" << endl;
        cout << "Enter your choice: ";
   
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear(); // 
            cin.ignore(1000, '\n'); 
            continue; 
        }
        
        switch (choice) {
            case 1: {
                Player newPlayer;
                cout << "Enter Nickname: ";
                
                // Clear the newline character left in the buffer by 'cin >> choice' before using getline
                cin.ignore(1000, '\n'); 
                getline(cin, newPlayer.nickname); // Safely read strings with spaces [cite: 79]
                
                cout << "Enter Age: ";
                // Adding basic validation here as well for consistency
                while (!(cin >> newPlayer.age)) {
                    cout << "Invalid input. Enter a valid number for age: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                cout << "Enter Score 1: ";
                while (!(cin >> newPlayer.score1)) {
                    cout << "Invalid input. Enter a valid number for Score 1: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                cout << "Enter Score 2: ";
                while (!(cin >> newPlayer.score2)) {
                    cout << "Invalid input. Enter a valid number for Score 2: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                addRecord(newPlayer);
                cout << "Player added successfully!" << endl;
                break;
            }
            case 2:
                cout << "\n--- All Player Records ---" << endl;
                viewRecords();
                break;
            case 3:
                cout << "\n--- Average Scores ---" << endl;
                computeAverage();
                break;
            case 4:
                cout << "\n--- Player(s) with Maximum Average ---" << endl;
                showMaxAverage();
                break;
            case 5:
                cout << "\n--- Player(s) with Minimum Average ---" << endl;
                showMinAverage();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);
    
    return 0;
}