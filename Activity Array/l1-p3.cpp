//l1-p3
#include <iostream>
using namespace std;

int main(){
    //max and min

    int max, min, max2, min2;
    int arrNum[10];

    cout<<"Enter ten numbers:"<<endl;
    for(int i = 0; i<10; i++){
        cin>>arrNum[i];
    }

    max = arrNum[0];
    min = max;
    max2 = arrNum[0];
    min2 = max2;
    //find the 

    for(int i = 0; i<10; i++){
        if(max<arrNum[i]){
            max=arrNum[i];
        }
        else if(min>arrNum[i]){
            min = arrNum[i];
        }
    }

     for(int i = 0; i<10; i++){
        if(max2 < arrNum[i] && arrNum[i] != max ){
            max2 = arrNum[i];
        }
        else if(min2 > arrNum[i] && arrNum[i] != min ){
            min2 = arrNum[i];
        }
    }

    cout<<"First to the highest: "<<max<<endl;
    cout<<"Second to the highest: "<<max2<<endl;
    cout<<"First to the lowest: "<<min<<endl;
    cout<<"Second to the lowest: "<<min2<<endl;

    return 0;

}