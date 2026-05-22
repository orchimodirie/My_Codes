//problem 6
#include <iostream>
using namespace std;

void sumArray (int array[]){
    int odd = 0;
    for(int i = 0; i < 10; i++){
        if(array[i] % 2 == 1){
            odd += array[i];
        }
    }
    cout<<"The sum of all odd numbers is "<<odd<<endl;
}

void getInput(int arrNum[]){
    for(int i = 0; i<10; i++){
            cin>>arrNum[i];
        }
}


int main(){
    int arrNum[10];

    cout<<"Enter 10 numbers: ";
    getInput(arrNum);
    sumArray(arrNum);
 
    return 0;
}