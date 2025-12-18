#include <iostream>
#include <cmath>
using namespace std;

int main() {
double GeoMean;
double n1, n2 ,n3;

cout<<"Input 3 numbers successively with space: \n";
cout<<"---> ";
cin>>n1>>n2>>n3;

double product = n1*n2*n3;

 GeoMean = cbrt(product);

 cout<<"The cube root of the numbers is "<<GeoMean<<endl;

 return 0;




}
