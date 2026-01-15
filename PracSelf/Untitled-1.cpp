#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/*

*/
struct Car{
    string plateNumber = "EMPTY";
    string ownerName = "EMPTY";
    int hoursParked = 0;
    
};

// we need a function that looks what slot is empty
void parkingStatus(const Car parkingSlot[]){
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
    }
}

void parkCar(Car parkingSlot[]){
    // the parks a car and th eprogram seach for vacancy
    // if there is vacant space, it retrieve its details 
    // if not, display parking lot is full
    string plateNum;
    string ownName;
    int hours;
    bool carFound = false;
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
            
            carFound = true;
            break;
       }
       
    }

    if(!carFound){
        cout<<"No available parking space"<<endl;
       }
}

void retrieveCar(Car parkingSlot[]){
    string platenum;
    int totalFee;
    bool carFound = false;

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

            carFound = true;
            break;
        }
    }
    if(!carFound)
        {
            cout<<"No plate number "<<platenum<<" is found."<<endl;
        }

    
}



int main(){
    
    Car parkingSlot [5]; // array of structure
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
