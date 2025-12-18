#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
const double pi = acos(-1.0);

double cubeOp(double sides);
double sphereOp(double radius);
double rectanOp(double l, double w, double h);




int main(){
    char choices, cont1;
    double sides, cubeAns;
    double radius, sphereAns;
    double l, w, h, rectAns;

do {

	system("cls");

    cout<<"************************************************************\n";
    cout<<"		        Volume of Shapes\n";
    cout<<"************************************************************\n";
    cout<<"		[C] - Cube\n";
    cout<<"		[S] - Sphere\n";
    cout<<"		[R] - Rectangular Parallelepiped\n";
    cout<<"		[X] - EXIT\n";
    cout<<"************************************************************\n";


    cout<<"Choose your option: ";
    cin>>choices;


    switch (choices){
        case 'C':
        case 'c':
        	cout<<"You choose to solve the Volume of the Cube!\n";
            cout<<"Enter side: ";
            cin>>sides;
            cubeAns = cubeOp(sides);
            cout<<"The volume of the cube is "<<fixed<<setprecision(2)<<cubeAns<<endl;
            break;
            //FUNCTION FOR CUBE
        case 'S':
        case 's':
        	cout<<"You choose to solve the Volume of the Sphere!\n";
            cout<<"Enter the radius: ";
            cin>>radius;
            sphereAns = sphereOp(radius);
            cout<<"The volume of the sphere is "<<fixed<<setprecision(2)<<sphereAns<<endl;
            break;
            //FUNCTION FOR CUBE


        case 'R':
        case 'r':
        	cout<<"You choose to solve the Volume of the Rectangular Parallelepiped\n";
            cout<<"Enter length: ";
            cin>>l;
            cout<<"Enter width: ";
            cin>>w;
            cout<<"Enter height: ";
            cin>>h;
            
            rectAns = rectanOp(l, w, h);
            cout<<"The volume of the Rectangular Parallelepiped is "<<fixed<<setprecision(2)<<rectAns<<endl;
            break;
            //FUNCTION FOR CUBE

        case 'X':
        case 'x':
            cout<<"Thank you for using the program!"<<endl;
			return 0;
		
            

    };

if (choices != 'X' || choices != 'x')
    system("pause");
    


}while(cont1 != 'X');

if(cont1 == 'X')
    cout<<"Thank you for using the program!"<<endl;

return 0;
}



double cubeOp(double s){
    double result;
    result = s * s * s;

    return result;
}

double sphereOp(double radius){
    double result;
    result = (4.0/3.0) * pi * (radius * radius * radius);
    return result;
}

double rectanOp(double l, double w, double h){
    double result;
    result = l*w*h;
    return result;

}
