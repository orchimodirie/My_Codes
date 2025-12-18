#include <iostream>
#include <vector>
#include <cstdlib>

int main(){
    int n, up;

    do
    {
    system("cls");
    std::cout<<"Size: ";
    std::cin>>n;
    if (!(n >= 1 && n <= 100))
        std::cout<<"Try again (1 <= n <= 100)"<<std::endl;
    else
        break;
    }while (!(n >= 1 && n <= 100));

    std::vector<int>primes(n);
    std::vector<int>arrDwn(n);

    std::cout<<"Array elements: ";
    for(int i = 0; n > i; i++){
        std::cin>>primes[i];
    }

    int left = 0;
    int right = n-1;

    while (left < right)
    {
        if (primes[left] != primes[right]){
            std::cout<<"Not a palindrome"<<std::endl;
            return 0;
        }
        left++;
        right--; 
    }

    std::cout<<"Palindrome"<<std::endl;
    return 0;
}