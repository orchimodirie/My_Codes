#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double x1, x2, y1, y2;


    cout<<"Enter the coordinates of the first point: ";
    cin>>x1>>y1;

    cout<<"Enter the coordinates of the second point: ";
    cin>>x2>>y2;

    double d = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));


    cout<<"The Euclidean Distance of the two point is: "<<d<<endl;

    return 0;

    

}