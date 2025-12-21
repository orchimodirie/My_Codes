#include <iostream>
#include <vector>

int main(){
    int n, targ, indx = -1;

    std::cout<<"Size: ";
    std::cin>>n;
    std::vector<int>primes(n);

    std::cout<<"Array elements: ";
    for(int i = 0; n > i; i++){
        std::cin>>primes[i];
    }
    std::cout<<"enter the target: ";
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
    if (indx != -1)
        std::cout<<"The index of target is "<<indx<<std::endl;
    else
        std::cout<<"-1"<<std::endl;
}