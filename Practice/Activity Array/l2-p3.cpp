#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = acos(-1.0);
using namespace std;

void aSquare(){
    double sides;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF SQUARE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the side of the square: ";
    cin>>sides;

    double result = sides * sides;
    cout<<"\nThe area is "<<result<<" sq. units"<<endl;
}

void aRectangle(){
    double length, width;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF RECTANGLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the length and width of the rectangle: ";
    cin>>length>>width;

    double result = width * length;
    cout<<"\nThe area is "<<result<<" sq. units"<<endl;
}

void aTriangle(){
    double base, height;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF TRIANGLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the base and height of the triangle: ";
    cin>>base>>height;

    double result = .5*(base*height);
    cout<<"\nThe area is "<<result<<" sq. units"<<endl;
}

void aCircle(){
    double radius;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF CIRCLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;

    double result = pi * (radius * radius);
    cout<<fixed<<setprecision(1);
    cout<<"\nThe area is "<<result<<" sq. units"<<endl;
}

int main(){
    int option;

    bool loopCtrl = true;
    while(loopCtrl)
    {
        system("cls");
        cout<<"*********************"<<endl;
        cout<<"MENU"<<endl;
        cout<<"*********************"<<endl;
        cout<<"[1] - Area of square"<<endl;
        cout<<"[2] - Area of rectangle"<<endl;
        cout<<"[3] - Area of triangle"<<endl;
        cout<<"[4] - Area of circle"<<endl;
        cout<<"[5] - Exit"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;

        switch (option)
        {
        case 1:
            aSquare();
            break;
        case 2:
            aRectangle();
            break;
        case 3:
            aTriangle();
            break;
        case 4:
            aCircle();
            break;
        case 5:
            cout<<"Thank you!"<<endl;
            loopCtrl = false;
            break;
        default:
            cout<<"Invalid input! Try Again."<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        system("pause");
}
    return 0;
}