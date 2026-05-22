#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;
/*

*/
struct Car{
    string plateNumber = "EMPTY";
    string ownerName = "EMPTY";
    int hoursParked = 0;
    
};

// we need a function that looks what slot is empty
void parkingStatus(const vector<Car> &parkingSlot){
    //linear search algorithm for 5 slot
    // target is the word empty
    system("cls");
    //if the vector reach its end doesnt empty space, you should return no avaialbe space
    string target = "EMPTY";

    for(int i = 0; i <5; i++){
       if(parkingSlot[i].plateNumber == target){
        cout<<"The slot "<<i+1<<" is available"<<endl;
       }
       else{
        cout<<"The slot "<<i+1<<" is occupied by "<<parkingSlot[i].plateNumber<<". (Owner: "<<parkingSlot[i].ownerName<<")"<<endl;
       }
    };
}

void parkCar(vector<Car> &parkingSlot){
    // the parks a car and th eprogram seach for vacancy
    // if there is vacant space, it retrieve its details 
    // if not, display parking lot is full
    string plateNum;
    string ownName;
    int hours;
    system("cls");

    // linear search for slot vacancy
    for(int i = 0; i <5; i++){
       if(parkingSlot[i].plateNumber == "EMPTY" ){
            cout<<"The slot "<<i+1<<" is available"<<endl;
            cout<<"Enter your name: ";
            cin.ignore(); // catch the buffer
            getline(cin, parkingSlot[i].ownerName);

            cout<<"Enter your plate name: ";
            cin>>parkingSlot[i].plateNumber;
            
            break;
       }
       else if(i == 4 && parkingSlot[i].plateNumber != "EMPTY"){
        cout<<"No available parking space"<<endl;
       }
    };




}

void retrieveCar(vector<Car> &parkingSlot){
    string platenum;
    int totalFee;
    system("cls");
    cout<<"Enter the car's plate number: "<<endl;
    cin>>platenum;

    //check the platenum(target) using linear search

    for(int i = 0; i < 5 ; i++){
        if(parkingSlot[i].plateNumber == platenum)
        {
            //calculate the total fee
            

            cout<<"Plate number "<<parkingSlot[i].plateNumber<<" has found."<<endl;
            cout<<"How many hours parked?: ";
            cin>>parkingSlot[i].hoursParked;

            totalFee = 2 * parkingSlot[i].hoursParked;

            cout<<"Total cost: $"<<totalFee<<endl;


            //reset values
            parkingSlot[i].hoursParked = 0;
            parkingSlot[i].plateNumber = "EMPTY";
            parkingSlot[i].ownerName = "EMPTY";

            break;
        }

        if(i == 4 && parkingSlot[4].plateNumber != platenum)
        {
            cout<<"No plate number "<<platenum<<" is found."<<endl;
        }
    }

    
}

void detailSlot(const vector<Car> &parkingSlot){
int choice;

    system("cls");
    for(int i = 0; i <5; i++){
       if(parkingSlot[i].plateNumber == "EMPTY"){
        cout<<"The slot "<<i+1<<" is available"<<endl;
       }
       else{
        cout<<"The slot "<<i+1<<" is occupied by "<<parkingSlot[i].plateNumber<<"(Owner: "<<parkingSlot[i].ownerName<<")"<<endl;
       }
    };

    cout<<"Check Details of Slot: ";
    cin>>choice;

    choice -= 1;

    cout<<"Car owner: "<<parkingSlot[choice].ownerName<<endl;
    cout<<"Car plate number: "<<parkingSlot[choice].plateNumber<<endl;
    cout<<"Number of hours: "<<parkingSlot[choice].hoursParked<<endl;
}




int main(){
    Car kotse;
    vector<Car> parkingSlot (5);
    int choice;

    bool loopControl = true;
    while (loopControl)
    {
    system("cls");
    cout<<"=================================="<<endl;
    cout<<"     Welcome to Parking Haven"<<endl;
    cout<<"=================================="<<endl;
    cout<<" [1] Park"<<endl;
    cout<<" [2] Retrieve"<<endl;
    cout<<" [3] Check Details"<<endl;
    cout<<" [4] Exit"<<endl;
    cout<<"Choose your Desired action: ";
    cin>>choice;

        switch (choice)
        {
            case 1:
                parkCar(parkingSlot);
                break;
            case 2:
                // retrieve a car
                retrieveCar(parkingSlot);
                break;
            case 3:
                parkingStatus(parkingSlot);
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                loopControl = false;
                break;
            default:
                cout<<"Wrong Input! Try Again."<<endl;
                cin.clear();
                cin.ignore(100, '\n');
                break;
        }
        if(choice != 4)
            system("pause");
    }
    
  


    return 0;

}
