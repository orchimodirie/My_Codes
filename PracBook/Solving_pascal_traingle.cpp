#include <iostream>
using namespace std;

int main (){

    int n;

    cout<<"enter the number: ";
    cin>>n;



    for (int i = 1; i <= n; i++){ // contol how many rows
    int coef = 1;
        for(int j = n-i; j > 0; j--){
         cout<<" "; // run n-i times or for example here 5-1 = 4
        }
        for(int k = 1; k<=i; k++){

            cout<<coef;
            coef=coef*(i-k)/k;

        }
    cout<<endl;
    }
return 0;
} 