#include <iostream>
using namespace std;

int add(int a, int b){
    return a + b;
}

int add(int a, int b, int c){
    return a + b + c;
}

int add(int arrNum[]){
    int accum = 0;
    for(int i = 0; i < 4; i++){
            accum += arrNum[i];
    }

    return accum;
}

int main(){
    int a, b, c;
    int arrNum[4];

    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"The sum is: "<<add(a, b)<<endl;


    cout<<"Enter three numbers: ";
    cin>>a>>b>>c;
    cout<<"The sum is: "<<add(a, b, c)<<endl;


    cout<<"Enter four numbers: ";
    for(int i = 0; i<4; i++){
        cin>>arrNum[i];
    }
    cout<<"The sum is: "<<add(arrNum)<<endl;

}