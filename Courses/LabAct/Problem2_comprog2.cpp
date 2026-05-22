// problem 2 group MP1-3
// Abenoja
// Mayor
// Gagarino

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

// function 1 - Deposit money
void deposit(double &balance)
{
    system("cls");
    double newbalance;

    while (true) //  we added extra feature to check the proper amount of to be deposit money. If user input negative number it will result error warning.
    {
        cout << "========================" << endl;
        cout << "         Deposit" << endl;
        cout << "========================" << endl;
        cout << "Amount to deposit: ";
        cin >> newbalance;

        if (newbalance < 0)
        {
            cout << "You can't deposit negative number. " << "Try Again!" << endl;
        }
        else
        {
            balance += newbalance;
            break;
        }
    }

    cout << "Deposited: $" << fixed << setprecision(2) << newbalance << ". " << "New Balance: $" << balance << endl;
}

void withdraw(double &balance)
{
    system("cls");
    double newbalance;
    cout << "========================" << endl;
    cout << "        Withdraw" << endl;
    cout << "========================" << endl;
    cout << "Amount to withdraw: ";
    cin >> newbalance;

    // condtionals to check if the anount of new balance is valid

    if (balance >= newbalance)
    {
        balance -= newbalance;
        cout << "Withdrew $" << fixed << setprecision(2) << newbalance << ". " << "New Balance: $" << balance << endl;
    }
    else
        cout << "Insufficient funds! " << "Cannot Withdraw $" << fixed << setprecision(2) << newbalance << endl;
}

void checkBalance(const double &balance)
{
    system("cls");
    cout << "===============================" << endl;
    cout << " Current balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "===============================" << endl;
}

void applyInterest(double &balance)
{
    system("cls");
    double interest = balance * 0.05;
    balance += interest;

    cout << "========================================" << endl;
    cout << "Applied 5.00% interest." << endl;
    cout << "Interest added: $" << fixed << setprecision(2) << interest << endl;
    cout << "Interest Applied! New Balance: $" << balance << endl;
    cout << "========================================" << endl;
}

int main()
{
    double balance = 0.0; // our main variable for this bank system
    bool loopcontrol = true;
    int choiceMenu;

    while (loopcontrol)
    {
        system("cls");

        // menu interface
        cout << "====================================================" << endl;
        cout << "                Welcome to the Bank!" << endl;
        cout << "====================================================" << endl;
        cout << " [1] Deposit Money" << endl;
        cout << " [2] Withdraw Money" << endl;
        cout << " [3] Check Balance" << endl;
        cout << " [4] Apply Interest" << endl;
        cout << " [5] Exit" << endl;
        cout << "Choose the number of desired action: ";
        cin >> choiceMenu;

        switch (choiceMenu)
        {
        case 1:
            deposit(balance);
            break;
        case 2:
            withdraw(balance);
            break;
        case 3:
            checkBalance(balance);
            break;
        case 4:
            applyInterest(balance);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            loopcontrol = false;
            break;
        default:
            // to avoid infinite loop
            cout << "Invalid input! Try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        if (choiceMenu != 5)
        {
            system("pause");
        }
    }
}