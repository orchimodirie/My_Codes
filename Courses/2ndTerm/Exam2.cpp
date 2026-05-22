#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

class Student {
private:
    string name;
    string idNumber;
    double finalGrade;

public:
    //  Default Constructor
    // Initializes a new Student object with safe, default values
    Student() {
        name = "Unknown";
        idNumber = "000000";
        finalGrade = 0.0;
    }

    // Parameterized Constructor 
    Student(string n, string id, double grade) {
        name = n;
        idNumber = id;
        finalGrade = grade;
    }

    // Member function for Input
    void inputStudentData() {
        cout << "Enter student's full name: ";
        
        getline(cin >> ws, name); 
        
        cout << "Enter student ID: ";
        getline(cin, idNumber);
        
        cout << "Enter final grade (0-100): ";
        cin >> finalGrade;
    }

    // Member function for File Handling (Writing)
    // Takes an already open file stream by reference to save the data
    void saveToFile(ofstream& outFile) const {
        outFile << name << endl;
        outFile << idNumber << endl;
        outFile << finalGrade << endl;
    }

    static void readAndDisplayAll() {
        ifstream inFile("grades.txt");
        
        if (!inFile) {
            cout << "No records found. The file 'grades.txt' might not exist yet.\n";
            return;
        }

        string tempName, tempId;
        double tempGrade;
        double totalGrades = 0.0;
        int studentCount = 0;

        cout << "\n=================================================\n";
        cout << left << setw(25) << "Student Name" << setw(15) << "ID Number" << "Grade\n";
        cout << "=================================================\n";

       
        while (getline(inFile >> ws, tempName)) {
            getline(inFile, tempId);
            inFile >> tempGrade;

            cout << left << setw(25) << tempName << setw(15) << tempId << fixed << setprecision(2) << tempGrade << "\n";

            totalGrades += tempGrade;
            studentCount++;
        }

        inFile.close(); 
        cout << "-------------------------------------------------\n";
        if (studentCount > 0) {
            double average = totalGrades / studentCount;
            cout << "Total Students: " << studentCount << "\n";
            cout << "Class Average:  " << fixed << setprecision(2) << average << "\n";
        } else {
            cout << "No valid student data to calculate an average.\n";
        }
        cout << "=================================================\n";
    }
};

int main() {
    int choice;
    
    do {
        cout << "\n--- Student Grade Manager ---\n";
        cout << "1. Add a new student record\n";
        cout << "2. Display all records & class average\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        // input validation to prevent infinite loops if a user types a letter
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                Student newStudent;
                newStudent.inputStudentData();

               
                ofstream outFile("grades.txt", ios::app);
                if (outFile) {
                    newStudent.saveToFile(outFile);
                    cout << "Record saved successfully to grades.txt!\n";
                    outFile.close();
                } else {
                    cout << "Error: Could not open file for saving.\n";
                }
                break;
            }
            case 2:
               
                Student::readAndDisplayAll();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}