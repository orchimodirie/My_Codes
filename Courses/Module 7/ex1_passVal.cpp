#include <iostream>
using namespace std;

void PassbyValue(int x, int y);

int main() {

    int x = 1, y = 10;
    
    PassbyValue(x, y);

    cout << "\nWhat happens after ";
    cout << "calling the function...\n" << endl;

    cout << "Value of x: " << x << endl;
    cout << "\nValue of y: " << y << endl;

    return 0;
}

void PassbyValue(int a, int b) {
    cout << "When passed to function ";
    cout << "as value parameter...\n";

    a++;
    b--;

    cout << "\nValue of x: " << a << endl;
    cout << "\nValue of y: " << b << endl;
}
