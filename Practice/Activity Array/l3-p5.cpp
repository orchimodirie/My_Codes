//problem 5
#include <iostream>
using namespace std;
//function overloading

void linechar(){
    for(int i = 0; i<20; i++){
        cout<<"*";
    }
    cout<<"\n";
}

void linechar(char a){
    for(int i = 0; i<20; i++){
        cout<<a;
    }
    cout<<"\n";
}

void linechar(int loop){
    for(int i = 0; i<loop; i++){
        cout<<"*";
    }
    cout<<"\n";
}

void linechar(char a, int loop){
    for(int i = 0; i<loop; i++){
        cout<<a;
    }
    cout<<"\n";
}

int main(){
    linechar();
    linechar('@');
    linechar(10);
    linechar('#', 15);
    system("pause>0");

    return 0;

}

