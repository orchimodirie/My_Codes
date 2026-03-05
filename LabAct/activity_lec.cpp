#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

    const int NOOFCUST = 3;
    const int NOOFITEM = 4;


    struct name{
        string fname;
        string lname;
    };

    struct orderDates {
        int day;
        int month;
        int year;
    };

    struct orderDetails{
        string id;
        string name;
        double price;
        int quantities;
        
    };

    struct Customer{
        name name;
        string contactNo;
        orderDates dates;
        orderDetails items[NOOFITEM];
        double totalBill;

        Customer()
        {
            name.fname = "N/A";
            name.lname = "N/A";
            contactNo = "N/A";
            dates.day = 1;
            dates.month = 1;
            dates.year = 1;

            for(int i = 0; i < NOOFITEM; i++)
            {
                items[i].id = "N/A";
                items[i].name = "N/A";
                items[i].price = 0.0;
                items[i].quantities = 0;
            }

            totalBill = 0.0;
        }
        
    };


bool validDates(int d, int m, int y) //simple validation
{
    if( d > 30 || d < 0 ) return false;
    if( m > 12 || m < 0) return false;
    if( y < 0) return false;

    return true;
}

void addCustomer(Customer customer[]) {
    cout << "(Enter "<<NOOFCUST<<" customer)\n";
    for (int i = 0; i<NOOFCUST; i++){
        customer[i].totalBill = 0; 
        cout<<"\n--- CUSTOMER INFORMATION " << (i + 1) << " ---\n";
        cout<<"First name: ";
        getline(cin, customer[i].name.fname);
        cout<<"Last name: ";
        getline(cin, customer[i].name.lname);

        //valid contact info limited to 15
        do{
            string tempcontact; 
            cout<<"Contact info: ";
            getline(cin, tempcontact);

            if(tempcontact.length() > 15)
            {
                cout<<"Contact info must be 15 character only!"<<endl;
                cin.clear();
            }
            else
            {
                customer[i].contactNo = tempcontact;
                break;
            }
        } while(true);

        // valid dates
        bool valid = false;
        do {
            
            cout<<"Day: ";
            cin>>customer[i].dates.day;
            cout<<"Month: ";
            cin>>customer[i].dates.month;
            cout<<"Year: ";
            cin>>customer[i].dates.year;

            if(validDates(customer[i].dates.day, customer[i].dates.month, customer[i].dates.year))
            {
                valid = true;
            }
            else
            {
                cout << ">> Invalid date! Please try again.\n";
                cin.clear(); 
                cin.ignore(1000, '\n');
            }
        } while(!valid);

        cin.ignore();

        cout<<"\n(Enter "<< NOOFITEM <<" items)"<<endl;

        for(int j = 0; j<NOOFITEM; j++)
        {
            
            cout<<"---Item "<<j+1<<" ---" <<endl;
            cout<<"ID: ";
            getline(cin, customer[i].items[j].id);

            cout<<"Name: ";
            getline(cin, customer[i].items[j].name);

            cout<<"Price: ";
            cin>>customer[i].items[j].price; 

            cout<<"Quantity: ";
            cin>>customer[i].items[j].quantities;
            cin.ignore();
            
            customer[i].totalBill += (customer[i].items[j].price) * (customer[i].items[j].quantities);
        }
    }


}

void PrintDetails( Customer customer[NOOFCUST])
{
    cout << "\nSUMMARY REPORT" << endl;
    cout << right << setw(5) << "#" 
         << setw(25) << "Customer Name" 
         << setw(20) << "Order Date" 
         << setw(15) << "Items" 
         << setw(10) << "Price" 
         << setw(10) << "Quantity" << endl;

    for (int i = 0; i < NOOFCUST; i++) {
        string fullname = customer[i].name.lname + ", " + customer[i].name.fname;
        string dateStr = to_string(customer[i].dates.day) + "/" + 
                         to_string(customer[i].dates.month) + "/" + 
                         to_string(customer[i].dates.year);


        cout << right << setw(5) << (i + 1)
             << setw(25) << fullname
             << setw(20) << dateStr << endl;


        for(int j=0; j < NOOFITEM; j++) {
            cout << right << setw(5) << " " 
                 << setw(25) << " " 
                 << setw(20) << " " 
                 << setw(15) << customer[i].items[j].name
                 <<setw(10) << fixed << setprecision(2) << customer[i].items[j].price
                 << setw(10) << customer[i].items[j].quantities << endl;
        }

        cout << right << setw(75) << "----------------------"<<endl; 
        cout << right << setw(65) << "TOTAL PRICE:" 
             << setw(10) << fixed << setprecision(2) << customer[i].totalBill << endl;
        cout << endl; 
    }


}


int main() {
    Customer customer[NOOFCUST];

    addCustomer(customer);
    PrintDetails(customer);

    return(0);
}