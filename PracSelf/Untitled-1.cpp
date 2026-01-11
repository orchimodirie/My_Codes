#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

string room() {
    return "avaialble.";
}

int main() {
    string r = "", vil;
    int nights = 0, sum = 0;
    bool booked = false;
    int choice;
    double totalCost = 0;
    double userinput;

    do {
        cout << "\n1. Check room availablity.\n";
        cout << "2. Book a room.\n";
        cout << "3. Calculate the total cost of the day.\n";
        cout << "4. View booking details.\n";
        cout << "5. Exit the program.\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "1. Room type =";
            cin >> r;
            for (char& ch : r) ch = tolower(ch);
            if (r == "single" || r == "double" || r == "suite") {
                vil = room();
                cout << "Room type " << r << " is " << room() << endl;
            }
            else {
                cout << "Room " << r << " is " << "not available";
            }break;
        }
        case 2: {
            cout << "Room type =, Nights = ";
            cin >> r >> nights;

          

            for (char& ch : r) ch = tolower(ch);

            cout << fixed << setprecision(2);

            if (r == "single") {
                totalCost = nights * 100;

                cout << setprecision(2) << "Booked " << r << " for " << nights << " nights. Cost $" << totalCost << endl;
            }
            else if (r == "double") {
                totalCost = nights * 150;

                cout << "Booked " << r << " for " << nights << " nights. Cost $" << totalCost << endl;
            }
            else if (r == "suite") {
                totalCost = nights * 250;

                cout << "Booked " << r << " for " << nights << " nights. Cost $" << totalCost << endl; break;

            } break;
        }
        case 3: if (totalCost == 0) {
            cout << "The total cost is not calculated yet."; break;

        }
              cout << "Enter Total cost after booking =";
              cin >> userinput;

              if (totalCost = userinput) {
                  cout << "Total cost so far: $" << userinput << endl;
              }
              else {
                  cout << "The amount does not match total cost.";
              } break;

        case 4: {

            cout << "\nRoom Type =, Number of Nights =, Total Cost= ";
            cin >> r >> nights >> totalCost;
            cout << "\n=== Booking Details ===\n";
            cout << "Room Type = " << r << "\n|";
            cout << "Number of Nights = " << nights << "\n";
            cout << "Total Cost = &" << totalCost << "\n";
            break;
        }
        default:
            cout << "\nExiting program...\n";
        }

    } while (choice != 5);
    return 0;
}