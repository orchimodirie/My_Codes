//L1-P2
#include <iostream>
using namespace std;

int main (){
    int binaryNum[32];
    int decimal, remainder = 0;
    int index = 1;

    cout<<"Enter a Decimal number: ";
    cin>>decimal;

    while(decimal>0){
        remainder = decimal % 2;
        binaryNum[index] = remainder;
        decimal = decimal/2;
        index++;
    }

    for(int j = index - 1; j> 0; j--){
        cout<<binaryNum[j]<<" ";
    }



    return 0;
}