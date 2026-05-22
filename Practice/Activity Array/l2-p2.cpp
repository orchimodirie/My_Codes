#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){

    srand(time(nullptr));

    int tracker[10]; //to check for unique numbers
    int counter = 0;

    cout<<"Unique numbers: ";

    
    while(counter < 10){
        int r = rand() % 20 + 1;
        bool isDuplicate = false;

        //check if the generated random number has duplicate in the tracker
        for(int i = 0; i < counter; i++){
            if(r == tracker[i]){
                isDuplicate = true;
                break; // exit for loop if duplicate is found
            }
        }

        if(!isDuplicate){
            tracker[counter] = r;
            cout<<r<<" ";
            counter++;//if no unique number is found, it doesnt increment
        }
    }

    return 0;
}