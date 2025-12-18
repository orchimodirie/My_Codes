#include <iostream>
using namespace std;

int main(){
    int year;

    cout<<"Enter the Year: ";
    cin>>year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        cout<<year<<" is leap year\n";
    }
    else
    {
          cout<<year<<" is not a leap year\n";
    }

return 0;

}