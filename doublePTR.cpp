#include <iostream>
using namespace std;

int main() {
    //declare variable, ptr, and doubleptr
    int row = 3, col = 3;


    int **arr = new int*[row]; //declare an array of pointer

    for(int i = 0; i<row; i++){ //making a column
        arr[i] = new int[col];
    }

    //populating the 2d array

    for(int i = 0; i<row; i++)
    {
        cout<<"Row "<<i+1<<": "<<endl;
        for(int j = 0; j<col; j++)
        {
            cin>>arr[i][j];
        }
    }



    //accessing or printing out
    cout<<"The matrix: \n";
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}