#include <iostream>
using namespace std;

int main() {
    int grade;
    cout << "Enter grade: ";
    cin >> grade;

    if (grade >= 91 && grade <= 100) {
        cout << "Letter Grade: A";
    }
    else if (grade >= 81 && grade <= 90) {
        cout << "Letter Grade: B";
    }
    else if (grade >= 71 && grade <= 80) {
        cout << "Letter Grade: C";
    }

    else if (grade >= 61 && grade <= 70) {
    cout << "Letter Grade: D";
    }

    else if (grade >= 51 && grade <= 60) {
    cout << "Letter Grade: E";
    }

    else {
        cout << "Failed";
    }

    return 0;
}
