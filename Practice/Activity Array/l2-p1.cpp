#include <iostream>
#include <cmath> //ceil() and floor()
using namespace std;

int main(){
double num;

cout<<"Enter a number to be round of: ";
cin>>num;

double decimalVal = num - int(num);

if(decimalVal < .5){
    num = floor(num);
}
else if(decimalVal > .5){
    num = ceil(num);
}
else{
    if(static_cast<int>(num) % 2 == 0)
        num = floor(num);
    else if(static_cast<int>(num) % 2 == 1){
        num = ceil(num);
    }
}
cout<<"The round ofF value: "<<num<<endl;

return 0;

}
//p.s. i thought the problem is weird but it really exist called Banker's rounding