#include <iostream>
#include <cstring>
#include <cctype>

int main(){
    
    std::string name;

    std::cout<<"Input your word: ";
    std::cin>>name;

    for(char &c: name){
        c = toupper(c);
    }

    int left = 0;
    int right = name.length()-1;

    while (left < right)
    {
        if (name[left] != name[right]){
            std::cout<<"Not a palindrome"<<std::endl;
            return 0;
        }
        left++;
        right--; 
    }

    std::cout<<"Palindrome"<<std::endl;

    return 0;
}