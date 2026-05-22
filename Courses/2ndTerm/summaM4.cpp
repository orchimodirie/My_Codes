#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void writeFile() {
    string name;
    int age;
    string course;
    
    ofstream outFile("students.txt", ios::app); 
    if (!outFile) {
        cerr << "Unable to open file for writing.\n";
        return;
    }

    cout << "Enter student's name: ";
    getline(cin, name);

    cout << "Enter student's age: ";
    while (true) {
        if (cin >> age) {
            break;
        } else {
            cout << "Invalid age. Please enter numerical input: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter student's course: ";
    getline(cin, course);

    outFile << name << endl;
    outFile << age << endl;
    outFile << course << endl;
    
    cout << "Record saved successfully!\n\n";
}

void readFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Unable to open file for reading.\n";
        return;
    }

    string name, course;
    int age;
    int studentCount = 0;

    cout << "\n=== All Student Records ===" << endl;

    while (getline(inFile, name)) {
        inFile >> age;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline after age
        getline(inFile, course);

        studentCount++; 
        
        cout << "\nStudent #" << studentCount << ":" << endl;
        cout << "Name:   " << name << endl;
        cout << "Age:    " << age << endl;
        cout << "Course: " << course << endl;
    }

 
    cout << "\n---------------------------" << endl;
    cout << "Total number of students stored: " << studentCount << endl;
}

int main() {
    char choice;
    
    cout << "--- Student Database Program ---\n\n";
    
    do {
        writeFile();
        cout << "Would you like to add another student? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << endl;
    } while (choice == 'y' || choice == 'Y');

    readFile();
    
    return 0;
}