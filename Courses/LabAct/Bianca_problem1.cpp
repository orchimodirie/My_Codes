// Bianca_problem1

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

int roomType(string hotel_Room)
{
    if (hotel_Room == "Single" || hotel_Room == "single")
        return 1;
    else if (hotel_Room == "Double" || hotel_Room == "double")
        return 2;
    else if (hotel_Room == "Suite" || hotel_Room == "suite")
        return 3;
    else
        return 4;
}

struct account
{
    string roomType;
    int numNights;
    double totalCost;
};

void printAvailability(account &acc)
{
    string room;
    double costs = 0.0;
    double totalCosts = 0.0;
    int night, num;

    system("cls");

    cout << "We have 3 different roomtypes with different rates:\n";
    cout << "1. Single : $100 per night\n";
    cout << "2. Double : $150 per night\n";
    cout << "3. Suite  : $250 per night\n";

    cout << "Select your desired roomtype (1-3): ";
    cin >> night;

    switch (night)
    {
    case 1:
        cout << "Room type Single is available.";
        costs = 100.0;
        room = "Single";
        break;
    case 2:
        cout << "Room type Double is available.";
        costs = 150.0;
        room = "Double";
        break;
    case 3:
        cout << "Room type Suite is available.";
        costs = 250.0;
        room = "Suite";
        break;
    default:
        cout << "Room type Penthouse is not available.";
        return;
    }

    bool loopControl = true;

    while (loopControl)
    {
        cout << "\nEnter the number of nights you'll stay: ";
        cin >> num;

        if (num > 0)
        {
            loopControl = false;
        }
        else
        {
            cout << "Invalid number of nights. Please try again.\n";
        }
    }

    totalCosts = costs * num;

    acc.totalCost = totalCosts;
    acc.roomType = room;
    acc.numNights = num;

    cout << fixed << setprecision(2);
    cout << "\n==================================\n";

    if (num > 1)
        cout << "Booked " << acc.roomType << " room for " << acc.numNights << " nights.\n";
    else
        cout << "Booked " << acc.roomType << " room for " << acc.numNights << " night.\n\n";

    cout << "Cost: $" << acc.totalCost << "\n";
}

void checkRoom()
{
    string chosenRoom;

    system("cls");
    cout << "==========================================\n";
    cout << " Which room you want to check?: ";
    cin >> chosenRoom;

    for (size_t i = 0; i < chosenRoom.length(); ++i)
    {
        chosenRoom[i] = toupper(static_cast<unsigned char>(chosenRoom[i]));
    }

    if (chosenRoom == "SINGLE")
    {
        chosenRoom = "Single";
    }
    if (chosenRoom == "DOUBLE")
    {
        chosenRoom = "Double";
    }
    if (chosenRoom == "SUITE")
    {
        chosenRoom = "Suite";
    }

    if (chosenRoom == "Single" || chosenRoom == "Double" || chosenRoom == "Suite")
        cout << " The room type " << chosenRoom << " is available.\n";
    else
    {
        cout << " The room type " << chosenRoom << " is not available.\n";
        return;
    }
}

void totalCost(const account &acc)
{
    system("cls");
    cout << "===========================\n";
    cout << " Total cost: $" << acc.totalCost << "\n";
}

void bookingDetails(const account &acc)
{
    system("cls");
    cout << "=== Booking Details ===\n";
    cout << " Room Type: " << acc.roomType << "\n";
    cout << " Number of Night/s: " << acc.numNights << "\n";
    cout << " Total Cost: $" << acc.totalCost << "\n";
}

int main()
{
    account acc;

    bool loopControl = true;

    while (loopControl)
    {
        int menuChoice;
        system("cls");
        cout << "==============================================\n";
        cout << "              Hotel Booking System             \n";
        cout << "==============================================\n";
        cout << " Choose Actions:\n";
        cout << "  1. Check Availability\n";
        cout << "  2. Book Room\n";
        cout << "  3. Calculate total cost\n";
        cout << "  4. View Booking Details\n";
        cout << "  5. Exit\n";

        cout << "Enter the number of desired action: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            checkRoom();
            break;
        case 2:
            printAvailability(acc);
            break;
        case 3:
            totalCost(acc);
            break;
        case 4:
            bookingDetails(acc);
            break;
        case 5:
            cout << "Exiting program...\n";
            loopControl = false;
            break;
        default:
            cout << "Invalid Input! Try again\n";
            break;
        }

        if (menuChoice != 5)
            system("pause");
    }

    return 0;
}