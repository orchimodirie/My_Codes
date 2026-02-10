// Banking Application

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
const int MaxAccount = 10;

/*
    Program functions:
        add, search, update, delete, d customers details display

    Account:
        name, account number, balance
*/

/*
    first column = name
    second = account number
    third = balance
*/
void AddAccount(string account[][3], int &count);
void SearchAcc(string account[][3], const int &count);
void UpdateCustomer(string account[][3], const int &count);
void DeleteCustomer(string account[][3], int &count);
void DisplayAll(string account[][3], const int &count);
void DisplayAcc(string account[][3], int row);
bool accountexist(string account[][3], string accNum, const int &count);

int main()
{
    int count = 0; // this hold the number of accounts available. Very crucial variable
    string account[MaxAccount][3];

    int option;

    bool loopCtrl = true;
    while (loopCtrl)
    {
        system("cls");
        cout << "*********************" << endl;
        cout << "MENU" << endl;
        cout << "*********************" << endl;
        cout << "[1] - Add Customer" << endl;
        cout << "[2] - Search Customer" << endl;
        cout << "[3] - Update Customer" << endl;
        cout << "[4] - Delete" << endl;
        cout << "[5] - Display" << endl;
        cout << "[6] - Exit" << endl;
        cout << "---------------------" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.clear();
        cin.ignore(1000, '\n');
        switch (option)
        {

        case 1:
            AddAccount(account, count);
            break;
        case 2:
            SearchAcc(account, count);
            break;
        case 3:
            UpdateCustomer(account, count);
            break;
        case 4:
            DeleteCustomer(account, count);
            break;
        case 5:
            DisplayAll(account, count);
            break;
        case 6:
            cout << "Thank you!" << endl;
            loopCtrl = false;
            break;
        default:
            cout << "Invalid input! Try Again." << endl;
            break;
        }

        system("pause");
    }
}
bool accountexist(string account[][3], string accNum, const int &count)
{

    for (int i = 0; i < count; i++)
    {
        if (account[i][1] == accNum)
        {
            return true;
        }
    }
    return false;
}

void AddAccount(string account[][3], int &count)
{
    system("cls");
    string accNum;
    if (count >= MaxAccount)
    {
        cout << "Maximum Account Reached" << endl;
        return;
    }

    cout << "Name: ";
    getline(cin, account[count][0]);

    while (true)
    {
        cout << "Account Number: ";
        getline(cin, accNum);

        if (accountexist(account, accNum, count))
        {
            cout << "Account number already exsit! Try Unique number!" << endl;
        }
        else
        {
            account[count][1] = accNum;
            break;
        }
    }
    cout << "Balance: ";
    getline(cin, account[count][2]);

    count++;
};

void SearchAcc(string account[][3], const int &count)
{
    system("cls");
    string lookfor;
    int itr = 0;
    cout << "Enter the account number: ";
    cin >> lookfor;

    bool checker = false;

    for (itr; itr < count; itr++)
    {
        if (lookfor == account[itr][1])
        {
            checker = true;
            break;
        }
        else
            continue;
    }

    if (checker)
    {
        DisplayAcc(account, itr);
    }
    else
        cout << "No customer with " << lookfor << " Account number is found" << endl;
};

void UpdateCustomer(string account[][3], const int &count)
{
    system("cls");
    string lookfor;
    int itr = 0;
    cout << "Enter the account number: ";
    cin >> lookfor;
    cin.clear();
    cin.ignore(1000, '\n');
    bool checker = false;

    for (itr; itr < count; itr++)
    {
        if (lookfor == account[itr][1])
        {
            checker = true;
            break;
        }
        else
            continue;
    }

    if (checker)
    {
        cout << "Name: ";
        getline(cin, account[itr][0]);
        cout << "Account Number: ";
        getline(cin, account[itr][1]);
        cout << "Balance: ";
        getline(cin, account[itr][2]);
    }
    else
        cout << "No customer with " << lookfor << " Account number is found" << endl;
}

void DeleteCustomer(string account[][3], int &count)
{
    system("cls");
    string lookfor;
    int itr = 0;
    cout << "Enter the account number: ";
    cin >> lookfor;

    bool checker = false;

    for (itr; itr < count; itr++)
    {
        if (lookfor == account[itr][1])
        {
            checker = true;
            break;
        }
        else
            continue;
    }

    if (checker)
    {
        for (int i = itr; i < count-1; i++)
        {
            account[i][0] = account[i + 1][0];
            account[i][1] = account[i + 1][1];
            account[i][2] = account[i + 1][2];
        }

        count--;
    }
    else
        cout << "No customer with " << lookfor << " Account number is found" << endl;
}

void DisplayAll(string account[][3], const int &count)
{
    system("cls");
    if (count == 0)
    {
        cout << "No customer yet" << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            
            if (account[i][0] != " ")
            {
                cout<<"\nCustomer "<<i+1<<endl;
                DisplayAcc(account, i);
            }
            else
                continue;
        }
    }
}

void DisplayAcc(string account[][3], int row)
{

    cout << "==================================" << endl;
    cout << "Customer name: " << account[row][0] << endl;
    cout << "Account Number: " << account[row][1] << endl;
    cout << "Balance: " << account[row][2] << endl;
    cout << "==================================" << endl;
}
