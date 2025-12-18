#include <iostream>
using namespace std;

int main()
{
int choice;
double balance = 1000.0;
double deposit, withdraw;

    cout<<"Welcome to MyATM\n";
        cout<<"1. Deposit\n";
        cout<<"2. Withdraw\n";
        cout<<"3. Check Balance\n";
        cout<<"4. Exit\n";


    cout<<"Enter your Choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:{
            cout<<"Enter the amount to be deposit:  ";
            cin>>deposit;
            balance = balance + deposit;
        break;
        }
        case 2:{
            cout<<"Enter the amount to be withdraw:  ";
            cin>>withdraw;

            if (withdraw > balance){
                cout<<"Insufficient Balance\n";
                return 0;
            }
            
            else{
            balance = balance - withdraw;
            }
        break;   
        }

    }






cout<<"thank you for using our service\n";
cout<<"Here is your new balance, "<<balance<<endl;

return 0;


}