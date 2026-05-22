#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    double balance = 1000.00;

string currentRoomType = "None";
int currentNights = 0;
double currentTotalCost = 0.0;

int choice;
cout<< fixed << setprecision(2);

do {
cout<< "------Menu Display------";
cout<< "\n------------------------" << endl;
cout<< "1. Book Room and Pay. " << endl;
cout<< "2. Check Balance" << endl;
cout<< "3. View Booking and Payment Details" << endl;
cout<< "4. Exit" << endl;
cout<< "Enter your Choice: ";
cin>> choice;
cout<< endl;

switch (choice) {    
    case 1:{string RoomType;
    int nights;
    double rate = 0.0;
    
    cout<< "Enter Room Type (Single/Double/Suite): ";
    cin>> RoomType;
    
    cout<< "Enter Number of Nights:";
    cin>> nights;
    
    if (RoomType == "Single"){
        rate = 100.00;
    } else if (RoomType == "Double"){
        rate = 150.00;
    } else if (RoomType == "Suite"){
        rate = 250.00;
    } else {
        cout<< "Invalid Room Type!" << endl;
        
 break;
    }
    
    
    double totalCost = rate*nights;
    if (balance >=totalCost){
        balance -=totalCost;
        
        currentRoomType = RoomType;
        currentNights = nights;
        currentTotalCost = totalCost;
        
        cout<< "Booked " << RoomType << " Room for " << nights << " Nights. Cost: $ " <<totalCost<<endl;
        
        cout<< "Remaining balance: $ " << balance << endl;
        cout<< endl;
        cout<< endl;
    } else {
        cout<< "Insufficient Funds! Cannot Book the Room." <<endl;
        cout<< endl;
        cout<< endl;
    }
    break;
    }
    case 2:
    cout<<"Current Balance:$ "<< balance << endl;
    cout<< endl;
    cout<< endl;
    break;
    
    
    case 3:
    cout<< "=== Booking and Payment Details ===" << endl;
    cout<< "Room Type: " << currentRoomType << endl;
    cout<< "Number of Nights: " << currentNights << endl;
    cout<< "Total cost: $" << currentTotalCost << endl;
    cout<< "Remaining Balance: $" << balance << endl;
    cout<< endl;
    cout<< endl;
    break;
   
    case 4:
    cout<< "Exiting Program..." << endl;
    break;
    
    default:
    cout<< "Invalid Choice. Please Try Again." << endl;
    cout<< endl;
}

} while (choice !=4);
return 0;
}