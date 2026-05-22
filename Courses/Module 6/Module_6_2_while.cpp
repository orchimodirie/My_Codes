#include <iostream>
using namespace std;

/* Write a program which is a custom countdown from an inputted number down to
1, and displays the word, “FIRE!” */

int main(){

    int n, counter = 1;
    cout<<"Enter the ending number : ";
    cin >> n;

   while(counter <= n){
    cout<<counter<<", ";
    ++counter;
   }

   cout<<"END!";

return 0;

}