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
    
    for (int i = n-1; i >= 0; i--){
        arrDwn[up] = primes[i];
        up++;
    }

    for (int i = 0; i < n; i++)
    {
       if (arrDwn[i] == primes[i]){
        continue;
       }
       else
       {
        std::cout<<"Not Palindrome"<<std::endl;
        return 0;
       }
    }
    
    std::cout<<"It's Palindrome"<<std::endl;
    return 0;
}   