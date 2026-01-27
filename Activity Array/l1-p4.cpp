#include <iostream>
#include <cstring> // to get the length
using namespace std;

int main(){

    char word [50];
    cout<<"Enter a word: ";
    cin.getline(word, 50);

    int length = strlen(word);
    int up = 0;
    int down = length - 1;

    bool isPalindrome = true;

    //this is two pointer technique that check if the last-start and start-last of character
    while(up < down){
        if(word[up] != word[down]){
            isPalindrome = false;
            break;
        }
        up++;
        down--;
    }

    if(isPalindrome)
        cout<<word<<" is a palindrome"<<endl;
    else
        cout<<word<<" is not palindrome"<<endl;

    return 0;
}