#include <iostream>
#include <vector>

int main(){
    int accum = 0;
    int n, targ, indx;

    std::cout<<"Size: ";
    std::cin>>n;
    std::vector<int>primes(n);

    std::cout<<"Array elements: ";
    for(int i = 0; n > i; i++){
        std::cin>>primes[i];
    }

    std::cin>>targ;

    for(int i = 0; n>i; i++){
        if (targ == primes[i]){
            indx = i;
            break;
        }
        else{
            continue;
        }

    }
    std::cout<<indx<<std::endl;
}