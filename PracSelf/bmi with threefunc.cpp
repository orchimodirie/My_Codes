#include <iostream>
#include <iomanip>
using namespace std;

double convertKilo(double pounds);
double convertMeter(double feet, double inches);

int main()
{

double lb, feet, inches;

    cout<<"Enter the pounds: ";
    cin>>lb;

    cout<<"Enter Feet and inches: ";
    cin>>feet>>inches;

    double kg = convertKilo(lb);
    double meter = convertMeter(feet, inches);

double bmi = kg/(meter*meter);

cout<<fixed<<setprecision(1);
cout<<"your bmi is "<<bmi<<endl;

return 0;

}



double convertKilo(double pounds)
{
double kilo = pounds*0.4535;

return kilo; 
}

double convertMeter(double feet, double inches)
{

double foot = inches/12;

double ffeet = feet + foot;
double meter = ffeet*0.3048;

return meter;
}