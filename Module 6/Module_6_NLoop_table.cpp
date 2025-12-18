#include <iostream>
using namespace std;

int main(){

int i,j;

for (i =1; i<=2;i++){ //outermost table (determine how many table you want to create)

    cout<<"Table of "<<i<<endl;

    for (j = 1; j<=10; j++){ // the main loop for the list of multiplication
        cout<<i<<"*"<<j<<"="<<(i*j)<<endl;
    }
cout<<"\n"; // make a space after the end of each table
}
    
return 0;
}
