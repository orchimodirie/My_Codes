#include <iostream>
using namespace std;

int main (){

    int row, column;

    cout<<"enter number of rows: ";
    cin>>row;

    cout<<"enter number of column: ";
    cin>>column;

    for(int i = 1; i <= column; i++){

        for(int j = 1; j <= row; j++){
            if ( j > row - i)
                cout<<j-(row-i)<<" ";
            else
                cout<<" ";
        }

        cout<<endl;
    }

return 0;
}