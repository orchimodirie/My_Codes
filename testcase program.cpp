#include <iostream>
using namespace std;










int validMonth(double m)
{
int month;
   
while (true){

    if (m != int(m)) {
        cout << "Invalid\n";
        continue;
    }

    month = int(m);


    if (month < 1 || month > 12){ 
    cout<<"Invalid";
    continue;

    }
}

    return month;

}








int main (){
    
    double m;
while (true){
    cout<<"Enter month: ";
    cin>>m;

    if (!(cin>>m)){         
        cout<<"invalid";
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
}

    cout<<"valid input month is "<< validMonth(m) <<endl;
    return 0;
    
}