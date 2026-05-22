#include <iostream>
#include <fstream>
using namespace std;

int main (){
    string name;
    int score;
    char choice;

    ofstream outFile("students.txt", ios::app);
    if(!outFile){
        cerr<<"Unable to open file for writing.\n";
        return 1;
    }

    do
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;

        outFile << name << " " << score << "\n";

        cout << "Add another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    

    ifstream inFile ("students.txt");
    if (!inFile)
    {
        cerr<<"Unable to open file for reading.\n";
        return 1;
    }

    cout << "\nStudent Records:\n";
    while(inFile >> name >> score)
    {
        cout << "name: " << name << ", score: "<< score << endl;
    }

    inFile.close();
    return 0;
}