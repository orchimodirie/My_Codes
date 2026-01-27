//L1-P2
#include <iostream>
using namespace std;

int main (){
    int binaryNum[32];
    int decimal;
    int index = 0;

    cout<<"Enter a Decimal number: ";
    cin>>decimal;

    if (decimal == 0) {
        cout << "Binary equivalent: 0" << endl;
        return 0;
    }

    while(decimal>0){
        binaryNum[index] = decimal % 2;
        decimal = decimal/2;
        index++;
    }

    cout<<"Binary equivalent: ";
    for(int j = index - 1; j>= 0; j--){
        cout<<binaryNum[j];
    }



    return 0;
}