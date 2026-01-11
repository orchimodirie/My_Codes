// problem 3 group MP1-3
// Abenoja - programmed this 
// Mayor
// Gagarino
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

    /*
    merong problem here since the input os string then what if the user capitalized certain character
    or the input is all llowercase? because of that i plan to capitalize the input before checking
    */

    for (char &c : roomchoice)
    {
        c = toupper(c);
    }

    if (roomchoice == "SINGLE")
    {
        selectedroom = "Single";
        priceRoom = 100.0;
    }
    else if (roomchoice == "DOUBLE")
    {
        selectedroom = "Double";
        priceRoom = 150.0;
    }
    else if (roomchoice == "SUITE")
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
    /*
     I implement this looping structure here to check the input for the night. Imagine the user input zero or any negative number
    it would successfully book the room with zero cost or negative amount. That is not good cuz that doesnt happen in real life
    */
    bool loopControl = true;
    while (loopControl)
    {

        cout << "How many nights?: ";
        cin >> nights;

        if (nights > 0)
        {
            loopControl = false;
        }
        else
        {
            cout << "Invalid number of night/s! Try Again (Input > 0)" << endl;
        }
    }

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
        cout << fixed << setprecision(2);
        cout << "Booked " << selectedroom << " for " << nights << " nights." << " Cost: $" << totalCost << endl;
        cout << "Remaing Balance: $" << acc.balance << endl;
    }
    else
    {
        cout << "Insufficient funds! Cannot book the room." << endl;
    }
}

void checkBalance(const accountDetails &acc)
{
    system("cls");
    cout << fixed << setprecision(2);
    cout << "\n=====================================" << endl;
    cout << "Current Balance: " << "$" << acc.balance << endl;
}

void viewDetails(const accountDetails &acc)
{
    system("cls");
    cout << fixed << setprecision(2);
    cout << "\n=== Booking and Payment Details ===" << endl;
    cout << "   Room type: " << acc.room << endl;
    cout << "   Number of nights: "<<acc.numNights<<endl;
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
        // main interface
        system("cls");

        cout << "==============================================" << endl;
        cout << "              Welcome to the Hotel!           " << endl;
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
            break;
        case 2:
            checkBalance(account);
            break;
        case 3:
            viewDetails(account);
            break;
        case 4:
            cout << "\nExiting program..." << endl;
            looper = false;
            break;

        default:
         //to avoid infinite loop
            cout << "\nInvalid choice! Try Again." << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            break;
        }

        // it exits directly if user choose 4 (does not wait)
        if (choiceMenu != 4)
            system("pause");
    }

    return 0;
}
