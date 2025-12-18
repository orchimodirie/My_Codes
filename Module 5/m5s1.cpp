#include <iostream>
using namespace std;

int main (){
    int score = 1023;
    bool gamePaused = false;
    char action = 'x';

    if (score > 1000)
        cout<<"Your score is over 1000."<<endl;
    

    if (score % 2 == 0 )
        cout<<"Your score is odd."<<endl;
    else
        cout<<"Your score is even."<<endl;
}