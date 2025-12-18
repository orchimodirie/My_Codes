#include <iostream>
using namespace std;

int main(){
int no;
cout<<"Enter a number: ";
cin>>no;

if(no>=0){
    cout<<"it's a non negative number";
}

else if(no<0)
{
        cout<<"it's a negative number";
}

else
{
        cout<<"it's zero";
}

return 0;
}
