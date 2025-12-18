#include <iostream>
using namespace std;

int main(){
int month, day, year, daysinmonth;
string monthName;


cout << "Enter your birthday\n";
cout << "Month: ";
cin >> month;
cout << "Day: ";
cin >> day;
cout << "Year: ";
cin >> year;

if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2025) {
    cout << "Invalid";
    return 0;
}

 
switch(month){
    case 1:
    monthName = "January"; daysinmonth = 31; break; 
    case 2:
        monthName = "February"; daysinmonth = 28; break;
    case 3:
        monthName = "March"; daysinmonth = 31; break;
    case 4:
        monthName = "April"; daysinmonth = 30; break;
    case 5:
        monthName = "May"; daysinmonth = 31; break;
    case 6:
        monthName = "June"; daysinmonth = 30; break;
    case 7:
        monthName = "July"; daysinmonth = 31; break;
    case 8:
        monthName = "August"; daysinmonth = 31; break;
    case 9:
        monthName = "September"; daysinmonth = 30; break;
    case 10:
        monthName = "October"; daysinmonth = 31; break;
    case 11:
        monthName = "November"; daysinmonth = 30; break;
    case 12:
        monthName = "December"; daysinmonth = 31; break;
    default:
        cout << "Invalid ";
}

if (year % 4 == 0 && month == 2) 
    {
        daysinmonth = 29;
    }

if (day < 1 || day > daysinmonth) 

    {
        cout << "Invalid";
        return 0;
    }

cout << "Your birthday is " << monthName << " " << day << ", " << year << ".";
return 0;


}
