#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

float convertFtoC(float f)
{
    float c = (f-32.0)*(5.0/9.0);
    return c;

}

int main ()
{
 float fFahrenheit, fCelsius, fKelvin;
 
 cout<<"Type the Fahrenheit: ";

 cin>>fFahrenheit;

 fCelsius = convertFtoC(fFahrenheit);

 cout <<"Celsius is "<< fCelsius << endl;

 return 0;



}