//problem #3
#include <iostream>
using namespace std;

void calcFact(long long num, long long &factorial)
{
    for (int i = num; i > 0; i--)
    {
        factorial *= i;
    }
}

int main()
{
    long long num, factorial = 1;
    // pass by reference the factorial

    cout << "Enter a number: ";
    cin >> num;
    if (num < 0)
    {
        cout << "Factorial is undefined for negative numbers." << endl;
    }
    else
    {
        calcFact(num, factorial);
        cout << "The factorial of " << num << " is " << factorial << endl;
    }

    return 0;
}