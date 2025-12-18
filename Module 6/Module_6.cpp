#include <iostream>
using namespace std;


/* Write a program that
accepts an input
continuously as long
as the input is not 99. If
the input is 99, the
program must compute
the sum of the inputs
except for the sentinel
99 then exits.  */



int main(){

int n,k;

cout<<"Enter first number: ";
cin>>n;
cout<<"Enter last number: ";
cin>>k;

do { 

    cout<<n<<" ";
    n++;

} while(k /*last value*/ >= n /*first value*/);      // the code will exit, if you input 0
 
cout<<"Code has stopped"<<endl;

return 0;
}


/* Write a program
that displays the
number between
the starting value
and ending
value(inclusive)    */
