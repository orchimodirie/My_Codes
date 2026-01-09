#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct accountDetails
{

    double balance = 1000.0;

    string room = "None";

    int numNights = 0;

    double totalCost = 0.0;
};

void bookroom(accountDetails &acc)
{
    system("cls");
    // first choose a room

    // assigned price point for each room

    // check how many nights

    // calcute nights x selected room

    // acct balance - total cost

    // if okay then update the account details (struct)

    string roomchoice;
    string selectedroom;
    string hotel;
    double priceRoom;
    int nights;

   
        cout << "Choose your Room Type: " << endl;

        // first pili tayo ng options here
        cout << "-> Single" << endl;
        cout << "-> Double" << endl;
        cout << "-> Suite" << endl;

        cout << "Enter the number of desired Room: ";
        cin >> roomchoice;

        // dapat

        if (roomchoice == "Single" || roomchoice == "single")
        {
            selectedroom = "Single";
            priceRoom = 100.0;

        }
        else if (roomchoice == "Double" || roomchoice == "double")
        {
            selectedroom = "Double";
            priceRoom = 150.0;

        }
        else if (roomchoice == "Suite" || roomchoice == "suite")
        {
            selectedroom = "Suite";
            priceRoom = 250.0;
        }
        else
        {
            cout << "\nInvalid room Type!" << endl;
            cout << "Try valid room!" << endl;
            return;
        }

    cout << "How many nights?: ";
    cin >> nights;

    double totalCost = priceRoom * nights;

    // check if the balance is enough
    if (acc.balance >= totalCost)
    {
        acc.balance -= totalCost;

        // update the account
        acc.room = selectedroom;
        acc.numNights = nights;
        acc.totalCost = totalCost;

        cout << "\n=====================================" << endl;
        cout<<fixed<<setprecision(2);
        cout << "Booked " << selectedroom << " for " << nights << " nights." << " Cost: $" << totalCost << endl;
        cout << "Remaing Balance: $" << acc.balance << endl;
    }

    else
    {
        cout << "Insufficient funds! Cannot book the room."<<endl;
    }
}

void checkBalance(const accountDetails &acc)
{
    system("cls");
    cout << "\n=====================================" << endl;
    cout << "Current Balance: " << "$" << acc.balance << endl;
}

void viewDetails(const accountDetails &acc)
{
    system("cls");
    cout << "\n=== Booking and Payment Details ===" << endl;
    cout << "   Room type: " << acc.room << endl;
    cout << "   Total Cost: $" << acc.totalCost << endl;
    cout << "   Remaining Balance: $" << acc.balance << endl;
}

int main()

{

    accountDetails account;
    int choiceMenu;
    bool looper = true;

    while (looper)
    {

        system("cls");

        cout << "==============================================" << endl;
        cout << "                 Welcome!                     " << endl;
        cout << "==============================================" << endl;
        cout << " Choose Actions:    " << endl;
        cout << "  1. Book Room and Pay  " << endl;
        cout << "  2. Check Balance  " << endl;
        cout << "  3. View Booking and Payment Details:  " << endl;
        cout << "  4. Exit  " << endl;

        cout << "Choose the number of desired action: ";
        cin >> choiceMenu;

        switch (choiceMenu)
        {
        case 1:
            bookroom(account);
            looper = true;
            break;

        case 2:
            checkBalance(account);
            looper = true;
            break;

        case 3:
            viewDetails(account);
            looper = true;
            break;

        case 4:
            cout << "\nExiting program..." << endl;
            looper = false;
            break;

        default:
            cout << "\nInvalid choice! Exiting..." << endl;
            looper = false;
            break;
        }

        system("pause");
    }

    return 0;
}
