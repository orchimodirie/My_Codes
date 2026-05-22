#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
const int MAX = 10;
/*
    place order
    store menu items and their prices in 2d array
    customer can add items to their order
    remove
    view the current order calculate the total bill
    and apply discount 
*/

/* 
    MENU:
    burger - $10.0
    chicken = $5.5
    fries = $3.5
    pizza = $7.5
    tacos = $6.5
    ice cream = $3.5
    coke diet = $2.5
    iced tea = $2.5
    water = $1.0

*/

/*
    10% off if ordering 4 items
    25% off if ordering 9 items
*/


//data structre is 2d array, vertical where column 2 (index 1) is the prices
void showMenu(const string MenuList [][2]){
    cout<<"============================"<<endl;
    cout<<"             MENU"<<endl;
    cout<<"============================"<<endl;
    for (int i = 0; i < 9; i++)
    {
       cout<<i+1<<". "<< left << setw(13) << MenuList[i][0] << " - $" << MenuList[i][1] << endl;
    }
    
}

void placeOrder(string OrderList [][2], const string MenuList[][2], int &orderTracker){
    

    bool isnotFinished = true;
    while(isnotFinished){
        system("cls");
        showMenu(MenuList);
        int option;

        while(true){
            cout<<"What is your order? (choose 1-9): ";
            cin>>option;
            if(cin.fail() || option>9 || option<1){
                cout<<"Invalid Choice!"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }

        OrderList[orderTracker][0] = MenuList[option-1][0];
        OrderList[orderTracker][1] = MenuList[option-1][1];
        orderTracker++;

        cout<<"Successfully ordered "<<OrderList[orderTracker-1][0]<<endl;
        while(true){
            char proceed;
            cout<<"Do you want to order more? (y|n): ";
            cin>>proceed;
            
            proceed = tolower(proceed);
            if(proceed == 'y'){
                isnotFinished = true;
                break;
            }
            else if(proceed == 'n')
            {
                isnotFinished = false;
                break;
            }
            else{
                cout<<"Invalid input!"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
        }

    }

}

void showOrder(string OrderList [][2], int row)
{
    cout << "==================================" << endl;
    cout << "Food: "<<OrderList[row][0]<<endl;
    cout << "Price: "<<OrderList[row][1]<<endl;
    cout << "==================================" << endl;
}

void DisplayOrders(string OrderList[][2], const int &OrderTracker)
{
    system("cls");
    if (OrderTracker == 0)
    {
        cout << "No Order yet" << endl;
    }
    else
    {
        for (int i = 0; i < OrderTracker; i++)
        {
            
            if (OrderList[i][0] != " ")
            {
                cout<<"\nOrder "<<i+1<<endl;
                showOrder(OrderList, i);
            }
            else
                continue;
        }
    }
}

void RemoveOrder(string MenuList[][2], int &OrderTr){

}

double TotalBill(string OrderList[][2], const int &orderTracker){
    // we need to convert the string to double using std::stod()
    double totalCost [MAX];
    double Sum = 0;

    if(orderTracker == 0){
        return Sum;
    }
    else{
        for(int i = 0; i<orderTracker; i++){
            totalCost[i] = stod(OrderList[i][1]);
        } 
    }
   

    for(double d: totalCost){
        Sum += d;
    }

    if(orderTracker>=4 && orderTracker<9){
        return Sum - (Sum*.1);
    }
    else if(orderTracker>=9){
        return Sum - (Sum*.25);
    }
    else
        return Sum;
}


int main() {
    string OrderList [MAX][2];
    string MenuList[][2] = {
        {"Burger", "10.0"},
        {"Chicken", "5.5"},
        {"Fries", "3.5"},
        {"Pizza", "7.5"},
        {"Tacos", "6.5"},
        {"Ice Cream", "3.5"},
        {"Coke Diet", "2.5"},
        {"Iced tea", "2.5"},
        {"Water", "1.0"},
    };
    int orderTracker = 0, option;

    bool loopCtrl = true;
    while (loopCtrl)
    {
        system("cls");
        cout << "*********************" << endl;
        cout << "MENU" << endl;
        cout << "*********************" << endl;
        cout << "[1] - Add Order" << endl;
        cout << "[2] - Remove Order" << endl;
        cout << "[3] - View Order" << endl;
        cout << "[4] - Total Cost" << endl;
        cout << "[5] - Exit" << endl;
        cout << "---------------------" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.clear();
        cin.ignore(1000, '\n');
        switch (option)
        {

        case 1:
            placeOrder(OrderList, MenuList, orderTracker);
            break;
        case 2:
            break; 
        case 3:
            DisplayOrders(OrderList, orderTracker);
            break;
        case 4:
            cout<<"Total Bill: "<<TotalBill(OrderList, orderTracker)<<endl;
            break;
        case 5:
            cout << "Thank you!" << endl;
            loopCtrl = false; 
            break;
        default:
            cout << "Invalid input! Try Again." << endl;
            break;
        }

        system("pause");
    }

}
