#include <iostream>
using namespace std;
/* Write a program that
asks for a number
and displays it. The
program only
terminates when the
input zero(0). */

int main(){
    int n;

    do {
    cout<<"Enter number (0 to end): ";
    cin>>n;
    cout<<"You entered: "<<n<<"\n";

    }while(n!=0);
    return 0;
}