#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int magic, guess;
    magic = rand(); 
    cout<<"Enter your guess: ";
    cin>>guess;
    
if (guess == magic){
    cout<<"You're right, \n";
    cout<<magic<<" is the magics number."; 
}

else
{
    cout<<"You're guess is wrong.\n";
}

 return 0;
}