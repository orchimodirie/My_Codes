#include <iostream>
using namespace std;


int main(){

    int sum = 0, x;
    cout<<"Enter number : ";
    cin>>x;

   while(x == 99){
    sum += x;
    cout<<"Enter number : ";
    cin>>x;
   }

   cout<<"The sum: "<<sum;
    return 0;

}