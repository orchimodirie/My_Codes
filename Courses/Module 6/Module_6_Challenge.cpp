#include <iostream>
using namespace std;

int main(){
int i, j;

// i is the multiplicand
// j is the multiplier

// the code runs horizontally instead of vertical

    for (j = 1; j <= 10; j++)
    { 
        for (i = 1; i <= 2; i++)
        { 
            cout << i << "*" << j << "=" << (i*j) << "\t";
        }
        cout<<"\n";
    }
return 0;
}