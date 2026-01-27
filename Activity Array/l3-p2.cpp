#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = acos(-1.0);
using namespace std;

double aSquare(){
    double sides;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF SQUARE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the side of the square: ";
    cin>>sides;

    return (sides * sides);
}

double aRectangle(){
    double length, width;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF RECTANGLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the length and width of the rectangle: ";
    cin>>length>>width;

    return (width * length);
}

double aTriangle(){
    double base, height;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF TRIANGLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the base and height of the triangle: ";
    cin>>base>>height;

     return (.5*(base*height));
}

double aCircle(){
    double radius;
    cout<<"---------------------"<<endl;
    cout<<"AREA OF CIRCLE"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;

    return pi * (radius * radius);
}

int main(){
    int option;
    double result;

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
        cout<<"[5] - exit"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;
        bool isValidChoice = true;

            if(option <= 0 || option > 4)
                isValidChoice = false;

        switch (option)
        {
        case 1:
            result = aSquare();
            break;
        case 2:
            result = aRectangle();
            break;
        case 3:
            result = aTriangle();
            break;
        case 4:
            result = aCircle();
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

        if(isValidChoice)
            cout<<"The area is "<<result<<" sq. units"<<endl;

        system("pause");
    }
    return 0;
}