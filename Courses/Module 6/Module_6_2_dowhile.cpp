#include <iostream>
using namespace std;

int main(){
    int start, end;
    cout<<"Enter starting value: ";
    cin>>start;
    cout<<"Enter ending value: ";
    cin>>end;
if (end>start){
    do{
        cout<<start<<" ";
        start++;

    } while(start <= end);
}

else if (start > end){
    do{
        cout<<start<<" ";
        start--;
}while(end <= start);
}

return 0;

}