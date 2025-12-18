#include <iostream>
using namespace std;

void Duplicate(int& a, int& b, int& c) {
    int aM, bM, cM;
  cout<<"Enter multiplier for a: ";
  cin>>aM;
  cout<<"Enter multiplier for b: ";
  cin>>bM;
  cout<<"Enter multiplier for c: ";
  cin>>cM;

  a *= aM;
  b *= bM;
  c *= cM;

}

int main() {
    int x = 1, y = 3, z = 7;
    Duplicate(x, y, z);
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    return 0;
}



