#include <iostream>
using namespace std;
//write a program tha accepts a numnber n and display the sum of even numebr and the sum of odd numbers form 1 to n

int main (){
int startMonth, endMonth, month, sum = 0;

cout<<"Enter the start month: ";
cin>>startMonth;

cout<<"Enter the end month: ";
cin>>endMonth;

for (startMonth; startMonth <= endMonth; startMonth++){


    switch(startMonth){
        case 1:
            month = 31;
            break;
        case 2:
            month = 28;
            break;
        case 3:
            month = 31;
            break;
        case 4:
            month = 30;
            break;
        case 5:
            month = 31;
            break;
        case 6:
            month = 30;
            break;
        case 7:
            month = 31;
            break;
        case 8:
            month = 31;
            break;
        case 9:
            month = 30;
            break;
        case 10:
            month = 31;
            break;
        case 11:
            month = 30;
            break;
        case 12:
            month = 31;
            break;
        default:
            month = 0;
            break;

    }
//accumalator
     sum = sum + month;

}

cout<<"Total days is "<<sum<<endl;



return 0;
}