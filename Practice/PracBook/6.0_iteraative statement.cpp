#include <iostream>
using namespace std;
//write a program tha accepts a numnber n and display the sum of even numebr and the sum of odd numbers form 1 to n

int main (){
int i, n, even = 0, odd = 0;
cout<<"Enter a number: ";
cin>>n;

for (i = 1; i<=n; i++){

if(i % 2 == 0){
    even = even  + i;
}
else {
    odd = odd + i;
}

}

cout<<"Sum of even number: "<<even<<endl;
cout<<"Sum of odd number: "<<odd<<endl;

return 0;
}