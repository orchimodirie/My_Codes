#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib> // Added for system("cls")

using namespace std;
const int MaxAccount = 10;

/* Program functions:
        add, search, update, delete, display details
    
    Account Array Structure:
        Col 0 = name
        Col 1 = account number
        Col 2 = balance
*/

// Function Prototypes
void AddAccount(string account[][3], int &count);
void SearchAcc(string account[][3], const int &count);
void UpdateCustomer(string account[][3], const int &count);
void DeleteCustomer(string account[][3], int &count); 
void DisplayAll(string account [][3], const int &count);
void DisplayAcc(string account[][3], int row);
bool accountexist(string account[][3], string accNum, const int &count);

int main (){
    int count = 0;
    string account[MaxAccount][3];

    int option;
    bool loopCtrl = true;

    while(loopCtrl)
    {
        system("cls"); // Clear screen
        cout<<"*********************"<<endl;
        cout<<"MENU"<<endl;
        cout<<"*********************"<<endl;
        cout<<"[1] - Add Customer"<<endl;
        cout<<"[2] - Search Customer"<<endl;
        cout<<"[3] - Update Customer"<<endl;
        cout<<"[4] - Delete"<<endl;
        cout<<"[5] - Display"<<endl;
        cout<<"[6] - Exit"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;

       // Handle invalid integer input (prevents infinite loops)
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            option = -1; // Force default case
        } else {
            cin.ignore(1000, '\n'); // Clear buffer for next getline
        }

        switch (option)
        {
        case 1:
            AddAccount(account, count);
            break;
        case 2:
            SearchAcc(account, count);
            break;
        case 3:
            UpdateCustomer(account, count);
            break;
        case 4:
            DeleteCustomer(account, count);
            break;
        case 5:
            DisplayAll(account, count);
            break;
        case 6:
            cout<<"Thank you!"<<endl;
            loopCtrl = false;
            break;
        default:
            cout<<"Invalid input! Try Again."<<endl;
            break;
        }
        
        if(loopCtrl) system("pause");
    }
    return 0;
}

//checker if same account number exist.
bool accountexist(string account[][3], string accNum, const int &count){
    for(int i = 0; i<count; i++){
        if(account[i][1] == accNum){
            return true;
        }
    }
    return false;
}

void AddAccount(string account[][3], int &count){
    string accNum;

    // Add return statement to stop function if full
    if(count >= MaxAccount){
        cout<<"Maximum Account Reached. Cannot add more."<<endl;
        return; 
    }

    cout<<"Name: ";
    getline(cin, account[count][0]);

    while(true){
        cout<<"Account Number: ";
        getline(cin, accNum);
        
        if(accountexist(account, accNum, count)){
            cout<<"Account number already exists! Try a unique number!"<<endl;
        }
        else{
            account[count][1] = accNum;
            break;
        }
    }
    cout<<"Balance: ";
    getline(cin, account[count][2]);

    count++;
    cout << "Customer Added Successfully!" << endl;
};

void SearchAcc(string account[][3], const int &count){
    string lookfor;
    cout<<"Enter the account number: ";
    getline(cin, lookfor); 

    bool found = false;
    int i; 

    for(i = 0; i<count; i++){
        if(lookfor == account[i][1]){
            found = true;
            break;
        }
    }

    if(found){
        DisplayAcc(account, i);
    }
    else
        cout<<"No customer with Account number "<<lookfor<<" is found."<<endl;
};

void UpdateCustomer(string account[][3], const int &count){
    string lookfor;
    int itr = 0;
    cout<<"Enter the account number to update: ";
    getline(cin, lookfor); 

    bool found = false;

    for(itr = 0; itr<count; itr++){
        if(lookfor == account[itr][1]){
            found = true;
            break;
        }
    }

    if(found){
        cout << "--- Updating Customer ---" << endl;
        cout<<"New Name (Current: " << account[itr][0] << "): ";
        getline(cin, account[itr][0]);
        
        string newAcc;
        while(true){
            cout<<"New Account Number (Current: " << account[itr][1] << "): ";
            getline(cin, newAcc);
            
          
            if(newAcc != account[itr][1] && accountexist(account, newAcc, count)){
                 cout<<"That Account Number is taken by another customer!"<<endl;
            } else {
                account[itr][1] = newAcc;
                break;
            }
        }

        cout<<"New Balance: ";
        getline(cin, account[itr][2]);     
        cout << "Update Successful!" << endl;
    }
    else
        cout<<"No customer with Account number "<<lookfor<<" is found."<<endl;
}

void DeleteCustomer(string account[][3], int &count){
    string lookfor;
    int itr = 0;
    cout<<"Enter the account number to delete: ";
    getline(cin, lookfor); 

    bool found = false;

    for(itr = 0; itr<count; itr++){
        if(lookfor == account[itr][1]){
            found = true;
            break;
        }
    }

    if(found){
        for(int j = itr; j < count - 1; j++){
            account[j][0] = account[j+1][0];
            account[j][1] = account[j+1][1];
            account[j][2] = account[j+1][2];
        }
        
        // Decrease count so the last slot is effectively removed
        count--; 
        cout << "Customer deleted successfully." << endl;
    }
    else
        cout<<"No customer with Account number "<<lookfor<<" is found."<<endl;
}

void DisplayAll(string account [][3], const int &count){
    if (count == 0) {
        cout << "No records to display." << endl;
        return;
    }

    for(int i = 0; i<count; i++){
        DisplayAcc(account, i);
    }
}

void DisplayAcc(string account[][3], int row){
    cout<<"=================================="<<endl;
    cout<<"Customer name:  "<<account[row][0]<<endl;
    cout<<"Account Number: "<<account[row][1]<<endl;
    cout<<"Balance:        "<<account[row][2]<<endl;
    cout<<"=================================="<<endl;
}