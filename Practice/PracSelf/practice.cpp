// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int size;
    cout<<"enter size: ";
    cin>>size;
    int *ptr = new int[size];
    
    cout<<"Populate"<<endl;
    for(int i = 0; i<size; i++)
    {
        ptr[i] = i + size;
    }
    
    cout<<"last element is "<<ptr[size - 1];

    delete [] ptr;
    ptr = nullptr;
    
    return 0;
}