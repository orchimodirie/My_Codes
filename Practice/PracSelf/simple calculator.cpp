#include <iostream>
using namespace std;

int main(){
    double n, n2, result;
    char oper;

    cout<<"Enter the first number: \n";
    cin>>n;

    cout<<"Enter the operation(+, -, *, /): \n";
    cin>>oper;

    cout<<"Enter the seconn number: \n";
    cin>>n2;



    switch(oper){
        case '+':  result = n + n2;
        break;

        case '-':  result = n - n2;
        break;

        case '/': result = n / n2;
        break;

        case '*':  result = n * n2;
        break;

        default: cout<<"invalid";

        return 0;
    }

  cout<<"The result is "<< result << endl;

return 0;


}