#include <iostream>
using namespace std;

int Power(int x, int n) {
    if (n == 0){
        return 1;
    }
    else {
        return x * Power(x, n-1);
    }
}


/* power(5,3) = 5 *  */




int main() {
    int x, n;

    cout << "Enter the base (x): ";
    cin >> x;
    cout <<"Enter the exponent (n): ";
    cin >> n;

    
    int result = Power(x, n);
    cout << "Result: " << result << endl;
    return 0;
}


