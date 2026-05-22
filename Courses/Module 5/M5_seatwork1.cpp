#include <iostream>
using namespace std;

int main() {
    float m, d;
    int month, day;

    cout << "Enter month: ";
    cin >> m;

    cout << "Enter day: ";
    cin >> d;

    // Check if user entered whole numbers (integers)
    if (m != int(m) || d != int(d)) {
        cout << "Invalid: must be integers.\n";
        return 0;
    }

    // Now safely cast to int
    month = int(m);
    day = int(d);

    // Validate ranges
    if (month < 1 || month > 12) {
        cout << "Invalid month.\n";
        return 0;
    }

    if (day < 1 || day > 31) {
        cout << "Invalid day.\n";
        return 0;
    }

    cout << "Valid input!\n";
    return 0;
}
