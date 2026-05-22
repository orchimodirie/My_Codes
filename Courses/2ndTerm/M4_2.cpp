#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
     string name;
     string accNumber;
     double balance;
    public:
     BankAccount (string name, string accNumber, double balance = 0.0)
     {
        this->name = name;
        this->accNumber = accNumber;
        this->balance = balance;

     }

     void deposit(double depositedMoney)
     {
        balance += depositedMoney;
     }

     void withdraw(double withdrawMoney)
     {
        if(balance - withdrawMoney < 0 )
        {
            cout<<"Insufficient Funds!"<<endl;
        }
        else
        {
            balance -= withdrawMoney;
        }
     }

    void display()
    {
        
    }


};