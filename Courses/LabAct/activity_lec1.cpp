#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NOOFCUST = 5;
const int NOOFITEM = 5; 

struct name {
    string fname;
    string lname;
};

struct orderDates {
    int day;
    int month;
    int year;
};

struct orderDetails {
    string id;
    string name;
    double price;
    int quantities;
};

struct Customer {
    name name;
    string contactNo;
    orderDates dates;
    orderDetails items[NOOFITEM];
    double totalBill;
};

bool validDates(int d, int m, int y) //simple validation
{
    if( d > 30 || d < 0 ) return false;
    if( m > 12 || m < 0) return false;
    if( y < 0) return false;
    return true;
}

void addCustomer(Customer customer[]) {
 
    
    for (int i = 0; i < NOOFCUST; i++) {
        customer[i].totalBill = 0; 
        cout << "(Enter 5 customer)\n--- CUSTOMER INFORMATION " << (i + 1) << " ---\n ";
        
        cout << "First Name: ";
        getline(cin, customer[i].name.fname);
        cout << "Last Name: ";
        getline(cin, customer[i].name.lname);

        do {
            string tempcontact; // check first the number of char before inputing
            cout << "Contact No: ";
            getline(cin, tempcontact);

            if (tempcontact.length() > 15) {
                cout << "Contact info must be 15 character only!" << endl;
            } else {
                customer[i].contactNo = tempcontact;
                break;
            }
        } while (true);

        cout << "Order Date:" << endl;
        bool valid = false;
        do {
            cout << "Day: ";
            cin >> customer[i].dates.day;
            cout << "Month: ";
            cin >> customer[i].dates.month;
            cout << "Year: ";
            cin >> customer[i].dates.year;

            if (validDates(customer[i].dates.day, customer[i].dates.month, customer[i].dates.year)) {
                valid = true;
            } else {
                cout << " Invalid date! Please try again.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (!valid);

    
        cout << "Enter " << NOOFITEM << " items:" << endl;

        for (int j = 0; j < NOOFITEM; j++) {
            cout << "\n  Item " << (j + 1) << ":" << endl;
            cout << "  ID: ";
            cin >> customer[i].items[j].id;
            cin.ignore(); 
            cout << "  Name: ";
            getline(cin, customer[i].items[j].name);
            cout << "  Price: ";
            cin >> customer[i].items[j].price;
            cout << "  Quantity: ";
            cin >> customer[i].items[j].quantities;

            customer[i].totalBill += (customer[i].items[j].price * customer[i].items[j].quantities);
        }
        cin.ignore(); 
    }
    
    cout << "\nSUMMARY REPORT" << endl;
    cout << left << setw(5) << "#" 
         << setw(20) << "Customer Name" 
         << setw(15) << "Order Date" 
         << setw(15) << "Items" 
         << setw(10) << "Price" 
         << setw(10) << "Quantity" << endl;

    for (int i = 0; i < NOOFCUST; i++) {
        string fullname = customer[i].name.lname + ", " + customer[i].name.fname;
        string dateStr = to_string(customer[i].dates.day) + "/" + 
                         to_string(customer[i].dates.month) + "/" + 
                         to_string(customer[i].dates.year);

        // Print first line: Number, Name, Date
        cout << left << setw(5) << (i + 1)
             << setw(20) << fullname
             << setw(15) << dateStr << endl;

        // Print all items (Fixed loop)
        for(int j=0; j < NOOFITEM; j++) {
            cout << left << setw(5) << " " 
                 << setw(20) << " " 
                 << setw(15) << " " 
                 << setw(15) << customer[i].items[j].name
                 << setw(10) << fixed << setprecision(2) << customer[i].items[j].price
                 << setw(10) << customer[i].items[j].quantities << endl;
        }

        cout << right << setw(55) << "TOTAL PRICE:" 
             << setw(10) << fixed << setprecision(2) << customer[i].totalBill << endl;
        cout << endl; 
    }
}

int main() {
    Customer customer[NOOFCUST];
    addCustomer(customer);
    return 0;
}