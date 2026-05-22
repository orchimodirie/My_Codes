//Problem 4
#include <iostream>
using namespace std;

void getInputs(int &num1, int &num2){ //use pass by reference to update the value
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
}

void addition(int num1, int num2){
    cout<<"The sum is: "<<num1 + num2<<endl;
}

void subtract(int num1, int num2){
    cout<<"The difference is: "<<num1 - num2<<endl;
}

void multiplication(int num1, int num2){
    cout<<"The product is: "<<num1 * num2<<endl;
}

void division(int num1, int num2){
    if(num2 == 0){
        cout<<"Undefined!"<<endl;
        return;
    }
    else
    {
        cout<<"The qoutient is: "<<num1/num2<<endl;
    }
}

int main(){
    int option;
    int num1, num2;
    system("cls");
        cout<<"*********************"<<endl;
        cout<<"ARITHMETIC "<<endl;
        cout<<"*********************"<<endl;
        cout<<"[1] - Addition"<<endl;
        cout<<"[2] - Subtraction"<<endl;
        cout<<"[3] - Multiplication"<<endl;
        cout<<"[4] - Division"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;

        if(option >= 1 && option <= 4 )
        {
            getInputs(num1, num2); //function that get the two inputs

            switch (option)
            {
            case 1: addition(num1, num2); break;
            case 2: subtract(num1, num2); break;
            case 3: multiplication(num1, num2); break;
            case 4: division(num1, num2); break;
            }
        }
        else
        {
            cout<<"Invalid input!"<<endl;
        }
    return 0;
}