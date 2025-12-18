#include <iostream>
#include <math.h>  
#include <iomanip>
using namespace std;

int main() {
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
    return 0;
}
