#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class BankAccount
{
private:
    string name;
    string accountNum;
    double balance;

public:
    BankAccount(string a, string b, double c)
        : name(a), accountNum(b), balance(c) {}

    BankAccount()
    {
        name = "None";
        accountNum = "None";
        balance = 0.0;
    }

    void getterName()
    {
        cout << "Name: " << name << endl;
    }

    void setterDetails()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter account number: ";
        getline(cin, accountNum);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cin.ignore(); // ignore buffer for next inputs
    }
    void deposit(double depositValue)
    {
        balance += depositValue;
        cout << "Successfully deposited to the account" << endl;
    }

    void withdraw(double withdrawValue)
    {
        int tempbalance = balance;
        // catcher if balance is less than or equal zero
        if (balance <= 0)
        {
            cout << "You don't have sufficient balance!" << endl;
            return;
        }

        if (balance - withdrawValue < 0)
        {
            cout << "You don't have sufficient balance!" << "\nCalculation: (" << balance - withdrawValue << ")" << endl;

            return;
        }
        else
            balance -= withdrawValue;
    }

    void displayDetails() const
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Account number: "<<accountNum<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

void setterFunction(vector<BankAccount> &accounts)
{
    system("cls");
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "--- Account No. " << i+1 << " ---" << endl;
        accounts[i].setterDetails();
    }
}

void displayFunction(const vector<BankAccount> &accounts)
{
    system("cls");
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "--- Account No. " << i+1 << " ---" << endl;
        accounts[i].displayDetails();
        cout<<"\n";
    }
}

int main()
{
    int size, choice;
    cout << "Enter the number of accounts: ";
    cin >> size;
    vector<BankAccount> accounts(size);
    cin.ignore();

    while (true)
    {

        cout << "----------------------------------" << endl;
        cout << right << setw(17) << "Menu" << endl;
        cout << "----------------------------------" << endl;
        cout << right << setw(15) << "[1] setter" << endl;
        cout << right << setw(15) << "[2] display" << endl;

        cout << "----------------------------------" << endl;
        cout << "choose you option: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            setterFunction(accounts);
            system("pause");
            break;
        case 2:
            displayFunction(accounts);
            system("pause");
            break;
        case 3:
            /* code */
            break;

        default:
            cout<<"Invalid Option! Try Again!"<<endl;
            cin.clear();
            cin.ignore(1000, '/n')
        }
    }
    return 0;
}