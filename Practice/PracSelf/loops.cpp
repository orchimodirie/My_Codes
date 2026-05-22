#include <iostream>
using namespace std;

int main (){
    // in c_++ any non zero reutrn 0 znad zero rerturn fal;se
int found = 0, count = 5;
if (!found || --count == 0)
 cout << "danger" << endl;
cout << "count = " << found << endl;

return 0;
}