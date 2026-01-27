#include <iostream>
using namespace std;

void addition(){
    int num1, num2;
    cout<<"\nADDITION"<<endl;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    int result = num1 + num2;
    cout<<"The sum is "<<result<<endl;
}

void subtraction(){
    int num1, num2;
    cout<<" \nSUBTRACTION"<<endl;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    int result = num1 - num2;
    cout<<"The difference is "<<result<<endl;
}

void multiplication(){
    int num1, num2;
    cout<<" \nMULTIPLICATION"<<endl;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    int result = num1 * num2;
    cout<<"The product is "<<result<<endl;
}

void division(){
    int num1, num2;
    cout<<" \nDIVISION"<<endl;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    if(num2 == 0)
        cout<<"Undefined!"<<endl;
    else
    {
        int result = num1/num2;
        cout<<"The qoutient is "<<result<<endl;
    }
    
}

int main(){
    char option;

    bool loopCtrl = true;
    while(loopCtrl)
    {
        system("cls");
        cout<<"*********************"<<endl;
        cout<<"MENU"<<endl;
        cout<<"*********************"<<endl;
        cout<<"[A] - addition"<<endl;
        cout<<"[s] - subtraction"<<endl;
        cout<<"[M] - multiplication"<<endl;
        cout<<"[D] - division"<<endl;
        cout<<"[X] - Exit"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;
        
        switch (toupper(option))
        {
        case 'A':
            addition();
            break;
        case 'S':
            subtraction();
            break;
        case 'M':
            multiplication();
            break;
        case 'D':
            division();
            break;
        case 'X':
            cout<<"Thank you!"<<endl;
            loopCtrl = false;
            break;
        default:
            cout<<"Invalid input! Try Again."<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        system("pause");
    }

    return 0;
    
}