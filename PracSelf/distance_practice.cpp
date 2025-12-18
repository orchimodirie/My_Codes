#include <iostream>
#include <cmath>
using namespace std;

int main(){
double vi, vf, a, t;
cout << "Enter your Initial velocity: ";
cin>>vi;
cout << "Enter your acceleration : ";
cin>>a;
cout << "Enter your time : ";
cin>>t;


double s = (vi*t)+(a*pow(t,2))/2;

//convert to yard
double yard = s/0.9144;

cout<<"The Distance is "<<yard<<" yard"<<endl;

return 0;
}
