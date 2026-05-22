#include <iostream>
using namespace std;

int main(){

    int row, col;
    int arr[10][10];
    int sum = 0;

    cout<<"Enter the row: ";
    cin>>row;
    cout<<"Enter the col: ";
    cin>>col;

    //input
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i<row; i++){
        sum += arr[i][i];
    }
    
    cout<<"the result of trace matrix: "<<sum<<endl;
}