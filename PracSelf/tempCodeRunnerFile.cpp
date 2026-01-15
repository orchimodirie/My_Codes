#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <cctype>
using namespace std;

// Global variables
double balance = 1000.00;
string bookedRoomType = "";
int bookedNights = 0;
double totalCost = 0.0;

// Room prices
map<string, double> roomRates;

// Function to fix room name (Suite, Single, Double)
string toProper(string str) 
{
    string result = str;
    if (!result.empty()) 
    {
        result[0] = toupper(result[0]);
        for (size_t i = 1; i < result.length(); i++) 
        {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

// Initialize room rates
void initializeRates() 
{
    roomRates["Single"] = 100.0;
    roomRates["Double"] = 150.0;
    roomRates["Suite"] = 250.0;
}

// Menu option 1: Book room and pay
void bookRoomAndPay() 
{
    string roomType;
    int nights;
    
    cout << "Enter room type (Single/Double/Suite): ";
    cin >> roomType;
    
    string properRoom = toProper(roomType);
    
    if (properRoom != "Single" && properRoom != "Double" && properRoom != "Suite") 
    {
        cout << "Invalid room type!\n";
        return;
    }
    
    cout << "Enter number of nights: ";
    cin >> nights;
    
    if (nights <= 0) 
    {
        cout << "Number of nights must be positive!\n";
        return;
    }
    
    double cost = roomRates[properRoom] * nights;
    
    if (cost > balance) 
    {
        cout << "Insufficient funds! Cannot book the room.\n";
        return;
    }
    
    // Update everything
    balance -= cost;
    bookedRoomType = properRoom;
    bookedNights = nights;
    totalCost = cost;
    
    cout << fixed << setprecision(2);
    cout << "Booked " << properRoom << " room for " << nights << " nights. Cost: $" << cost << endl;
    cout << "Remaining balance: $" << balance << endl;
}

// Menu option 2: Check balance
void checkBalance() 
{
    cout << fixed << setprecision(2);
    cout << "Current balance: $" << balance << endl;
}

// Menu option 3: View booking and payment details
void viewBookingAndPaymentDetails() 
{
    if (bookedRoomType.empty()) 
    {
        cout << "No booking found.\n";
        return;
    }
    
    cout << fixed << setprecision(2);
    cout << "=== Booking and Payment Details ===\n";
    cout << "Room Type: " << bookedRoomType << endl;
    cout << "Number of Nights: " << bookedNights << endl;
    cout << "Total Cost: $" << totalCost << endl;
    cout << "Remaining Balance: $" << balance << endl;
}

// Show the menu
void showMenu() 
{
    int choice;
    
    while (true) 
    {
        cout << "\n========== HOTEL-BANKING HYBRID SYSTEM ==========\n";
        cout << "1. Book Room and Pay\n";
        cout << "2. Check Balance\n";
        cout << "3. View Booking and Payment Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (choice == 1) 
        {
            bookRoomAndPay();
        }
        else if (choice == 2) 
        {
            checkBalance();
        }
        else if (choice == 3) 
        {
            viewBookingAndPaymentDetails();
        }
        else if (choice == 4) 
        {
            cout << "Exiting program...\n";
            break;
        }
        else 
        {
            cout << "Invalid choice! Please enter 1-4.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

// Main function
int main() 
{
    // Initialize room rates
    initializeRates();
    
    // Start the program
    showMenu();
    
    return 0;
}