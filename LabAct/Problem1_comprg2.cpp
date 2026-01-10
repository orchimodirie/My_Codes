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

/* objective

Design a program for a hotel room booking system that allows users to:

Check room availability.
Book a room.
Calculate the total cost of the stay.
View booking details.
Exit the program.

*/

// ill be needing somthing thath coan hold the data
// i'lll use struct for these as what i have done with the problem 3

struct account
{

    string roomType = "None";
    int numNights = 0;
    double totalCost = 0.0;
};

void bookRoom(account &acc)
{
    /*
        this program will do the first option, book room and pay
        first we'll lete the user to choose specific room type
        then we assigned specific price for the room chosen
        we calculate the total cost by multiplying the night/s and room
        update the account
        and then confirm the booking details

    */
    string chosenRoom;
    double priceRoom;
    double totalCost;
    int night;

    system("cls");
    cout << "=======================================" << endl;
    cout << "     Choose the room type to book" << endl;
    cout << "=======================================" << endl;
    cout << "-> Single" << endl;
    cout << "-> Double" << endl;
    cout << "-> Suite" << endl;
    cout << "Type the chosen room type: ";
    cin >> chosenRoom;



    //Thyis will capitalized each char of string input. myw ay of handling the case
    for(char& c: chosenRoom ){
        c = toupper(c);
    }

    // we going to use if else for conditionals
    if (chosenRoom == "SINGLE"){
        priceRoom = 100.0;
        chosenRoom = "Single"; // I put this to maintain proper case for the input room
    }
    else if (chosenRoom == "DOUBLE"){
        priceRoom = 150.0;
        chosenRoom = "Double";
    }
    else if (chosenRoom == "SUITE"){
        priceRoom = 250.0;
        chosenRoom = "Suite";
    }
    else
    {
        // exit if not in the option
        cout << "Invalid input! Please Try Again." << endl;
        return;
    }

    

    /* 
        why i have loop controL?
        Im thinking what if the user put 0 or negative number.
        the bookroom function will run and you will successfully book a room
        but with negative or zero totalCost, that is not good.
        Therefore i will add a looping input for the night and check if the user input if valid
        if yes then it normally does it's own job
        
    */
    bool loopControl = true;
    while(loopControl){

    
    cout << "How many nights?: ";
    cin >> night;

    if(night > 0){
        loopControl = false;
    }
    else{
        cout<<"Invalid number of night/s! Try Again (Input > 0)"<<endl;
    }

    }

    // calculating total cost
    totalCost = priceRoom * night;

    // update inforamtion
    acc.totalCost = totalCost;
    acc.roomType = chosenRoom;
    acc.numNights = night;

    cout << fixed << setprecision(2) << endl;
    cout << "==================================" << endl;
    if (night > 1) // for singular night and plural nights
        cout << " Booked " << chosenRoom << " room for " << night << " nights. " << endl;
    else
        cout << " Booked " << chosenRoom << " room for " << night << " night. " << endl;
    cout << " Cost: $" << totalCost << endl;
}

void checkRoom()
{
    string chosenRoom;

    system("cls");
    cout<<"=========================================="<<endl;
    cout<<" Which room you want to check?: ";
    cin >> chosenRoom;

    for(char& c: chosenRoom ){ //capitalized the input
        c = toupper(c);
    }

    if (chosenRoom == "SINGLE"){ //this act as filter process to maintain the proper casing of the input string
        chosenRoom = "Single"; 
    }
    if (chosenRoom == "DOUBLE"){
        chosenRoom = "Double";
    }
    if (chosenRoom == "SUITE"){
        chosenRoom = "Suite";
    }

    if (chosenRoom == "Single" || chosenRoom == "Double" || chosenRoom == "Suite")
        cout << " The room type " << chosenRoom << " is available."<<endl;
    else
    {
        // exit if not in the option
        cout << " The room type " << chosenRoom << " is not available."<<endl;
        return;
    }

}

void totalCost(const account &acc)
{
    system("cls");
    cout << "===========================" << endl;
    cout << " Total cost: $" << acc.totalCost;
}

void bookingDetails(const account &acc)
{
    system("cls");
    cout << "=== Booking Details ===" << endl;
    cout << " Room Type: " << acc.roomType << endl;
    cout << " Number of Night/s: " << acc.numNights << endl;
    cout << " Total Cost: $" << acc.totalCost << endl;
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
            cout << "Exiting program..." <<endl;
            break;
        default:
            cout<<"Invalid Input! Try again"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            break;
        }
        
        if(menuChoice != 5)
         system("pause");
    }

    return 0;
}