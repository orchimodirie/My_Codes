// problem 1 group MP1-3
// Abenoja
// Mayor
// Gagarino
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct account
{

    string roomType = "None";
    int numNights = 0;
    double totalCost = 0.0;
};

void toLowerCase(string str){
    for(char& c: str){
        c = tolower(c);
    }
}
void bookRoom(account &acc)
{

    string chosenRoom;
    double priceRoom;
    double totalCost;
    int night;

    system("cls");
    cout << "=======================================" << endl;
    cout << "           BOOK A ROOM" << endl;
    cout << "=======================================" << endl;
    cout << "-> Single" << endl;
    cout << "-> Double" << endl;
    cout << "-> Suite" << endl;
    cout << "Type the chosen room type: ";
    cin >> chosenRoom;

    // Thyis will capitalized each char of string input. my way of handling the case
    toLowerCase(chosenRoom);

    // we going to use if else for conditionals
    if (chosenRoom == "single")
    {
        priceRoom = 100.0;
    }
    else if (chosenRoom == "double")
    {
        priceRoom = 150.0;
    }
    else if (chosenRoom == "suite")
    {
        priceRoom = 250.0;
    }
    else
    {
        // exit if not in the option
        cout << "Room type " << chosenRoom << " is not available." << endl;
        return;
    }

    // the loop is for input handling
    bool loopControl = true;
    while (loopControl)
    {

        cout << "How many nights?: ";
        cin >> night;

        if (night > 0)
        {
            loopControl = false;
        }
        else
        {
            cout << "Invalid number of night/s! Try Again (Input > 0)" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    // calculating total cost
    totalCost = priceRoom * night;

    // update inforamtion
    chosenRoom[0] = toupper(chosenRoom[0]);
    acc.totalCost = totalCost;
    acc.roomType = chosenRoom;
    acc.numNights = night;

    cout << fixed << setprecision(2) << endl;
    cout << "==================================" << endl;
    if (night > 1) // (formatiing purpose only, doesnt affect the logic)
        cout << " Booked " << chosenRoom << " room for " << night << " nights. " << endl;
    else
        cout << " Booked " << chosenRoom << " room for a night. " << endl;
    cout << " Cost: $" << totalCost << endl;
}

void checkRoom()
{
    string chosenRoom;

    system("cls");
    cout<<"==========================================" << endl;
    cout<<"           Check Available Room"<<endl;
    cout<<"==========================================" << endl;

    cout << " Which room you want to check?: ";
    cin >> chosenRoom;

    toLowerCase(chosenRoom);

    if (chosenRoom == "single" || chosenRoom == "double" || chosenRoom == "suite")
    {
        chosenRoom[0] = toupper(chosenRoom[0]); // capitalize for foramtting
        cout << " The room type " << chosenRoom << " is available." << endl;
    }
    else
    {
        // exit if not in the option
        cout << " The room type " << chosenRoom << " is not available." << endl;
        return;
    }
}

void totalCost(const account &acc)
{
    system("cls");
     cout << "===========================" << endl;
    if (acc.roomType == "None")
    {
        cout << "      NO BOOKING YET       " << endl;
    } 
    else 
    {
        cout << fixed << setprecision(2);
        cout << " Total Cost:     $" << acc.totalCost << endl;
    }
     cout << "===========================" << endl;
}

void bookingDetails(const account &acc)
{
    system("cls");

    if (acc.roomType == "None")
    {
        cout << "===========================" << endl;
        cout << "      NO BOOKING YET       " << endl;
        cout << "===========================" << endl;
    }
    else
    {
        cout << "=== Booking Details ===" << endl;
        cout << " Room Type: " << acc.roomType << endl;
        cout << " Number of Night/s: " << acc.numNights << endl;
        cout << " Total Cost: $" << acc.totalCost << endl;
    }
}

int main()
{
    account account; // the account variable we're all booking details will be stored

    // I use pass by reference for all the function

    /* We are going to loop the menu options here until the user choose exit
        - while loop with boolean control variable
        - switch case to choose which action
        - system pause at the end of loop so the can still be see beacuse;
        - I'm going to add system("cls") at the top of loop to make interface clean */

    bool loopControl = true;

    while (loopControl)
    { // loop
        int menuChoice;
        system("cls");
        cout << "==============================================" << endl;
        cout << "              Hotel Booking System         " << endl;
        cout << "==============================================" << endl;
        cout << " Choose Actions:    " << endl;
        cout << "  1. Check Availability" << endl;
        cout << "  2. Book Room" << endl;
        cout << "  3. Calculate total cost" << endl;
        cout << "  4. View Booking Details " << endl;
        cout << "  5. Exit " << endl;

        cout << "Enter the number of desired action: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            checkRoom();
            break;
        case 2:
            bookRoom(account);
            break;
        case 3:
            totalCost(account);
            break;
        case 4:
            bookingDetails(account);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            loopControl = false;
            break;
        default:
            // to avoid infinite loop
            cout << "Invalid Input! Try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        if (menuChoice != 5)
            system("pause");
    }

    return 0;
}