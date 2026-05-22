#include <iostream>
using namespace std;

/* Write a program
that reads three
integers and
displays the sum
of all the integers */

int main(){

    int counter, sum = 0, num;
    cout<<"Enter the numbers : ";


    for(counter = 1; counter <= 3 ; counter ++){
        cin>>num;
        sum += num;
    }

    cout<<"Sum : "<<sum;
    return 0;

}