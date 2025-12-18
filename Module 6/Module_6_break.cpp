#include <iostream>
using namespace std;

/* Write a program which is a custom countdown from an inputted number down to
1, and displays the word, “FIRE!” */

int main(){

int num = 1;
while(num <= 50){
cout<<"Value of variable num is "<<num<<endl;
     if (num == 3){
        break;
     }
    num++;
}

   cout<<"Out of while-loop";

return 0;

}