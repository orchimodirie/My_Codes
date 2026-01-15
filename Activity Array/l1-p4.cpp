#include <iostream>
#include <cstring> // to get the length
using namespace std;

int main(){

    char word [50];
    char compare[50];
    int j = 0;
    cout<<"Enter a word: ";
    cin.getline(word, 50);

    int length = strlen(word);

    for(int i = length - 1; i>=0; i--){
      compare[j] = word[i];
      ++j;
    }

   

    for(int i = 0; i<length; i++){
        if(compare[i] == word[i]){
            continue;
        }
        else{
            cout<<"Not palindrome"<<endl;
            return 0;  
        }
        cout<<"Palindrome"<<endl;
    }
}