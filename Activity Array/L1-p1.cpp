#include <iostream>
using namespace std;

int main(){
    int arrNum[10];

    cout<<"Enter number 10 numbers: "<<endl;
    for(int i = 0; i<10; i++){
        cin>>arrNum[i];
    }

    // I use simple bubble sort algorithm
    for(int i = 0; i<9; i++){
        for(int j = 0; j<10-i-1; j++){
            if(arrNum[j]>arrNum[j+1]){
                int temp = arrNum[j];
                arrNum[j] = arrNum[j+1];
                arrNum[j+1] = temp;
                
            }
        }
    }

    cout<<"Element value of array in ascending order"<<endl;
    for(int num: arrNum){
        cout<<num<<" ";
    }

    return 0;
}