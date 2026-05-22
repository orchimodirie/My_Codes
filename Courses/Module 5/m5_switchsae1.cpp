#include <iostream>
using namespace std;

int main() {
    int month = 11;   // user enters 13
    bool isValid = true;

    if (month < 1 || month > 12)
        isValid = false;

    if (isValid)
        cout << "Valid month!";
    else
        cout << "Invalid month!";
}
