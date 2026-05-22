#include <iostream>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    std::cout<<"Enter two number: ";
    std::cin>>a>>b;

    std::cout<<"The greater number is "<<max(a, b)<< std::endl;

    return 0;
}