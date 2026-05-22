#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int repetition(int n);

struct c_parameters
{
    double area;
    double circumference;
    double diameter;
};

c_parameters cirlce(double r);
double distance();

int main ()
{
    int n;
    double r;
    double e;

        cout<<"Enter a positive integer: ";
        cin>>n;

   
    cout<<"The factorial is: "<< repetition(n) << endl;
    cout<<"Great your function is working\n";

    // different function
    cout<<"\n\nLets us try diffrent function now\n";
    cout<<"Lets us try circles, enter the radius: \n";
    cin>>r;
 
    c_parameters cparam = cirlce(r); // fubction call and the variable cparam is storing the return value of the function

    cout<<"The area is: "<<cparam.area<<endl;
    cout<<"The circumference is: "<<cparam.circumference<<endl;
    cout<<"The diameter is: "<<cparam.diameter<<endl;

    // different function
    cout<<"\n\nLets us try diffrent function now\n";
    cout<<"Lets us try distance of two points\n";
    cout<<distance();

return 0;
 
}

c_parameters cirlce(double r) {
    
c_parameters cparam;

    cparam.area = 3.14159 * r * r;
    cparam.circumference = 3.14159 * 2 * r;
    cparam.diameter =  2 * r;

    return cparam;
}

double distance() {
    double x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point (x1,y1) separated by a space: ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second point (x2,y2) separated by a space: ";
    cin >> x2 >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);

    cout<<fixed<<setprecision(2);
    cout << "The Euclidean distance between the two points is: " << distance << "\n";
return distance;

}

int repetition(int n)
{
    int factorial = 1;

     for(int i=1; i<=n; i++)
    {
        factorial *= i;
    }
return factorial;
}

