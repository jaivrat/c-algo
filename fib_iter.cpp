//
//  fib_iter.cpp
//  
//

#include <iostream>


unsigned long long int fib_iter(int n)
{
    if(n<=1) return(n);
    
    unsigned long long int prev_prev = 0;
    unsigned long long int prev = 1;
    for(int i=2; i<=n; ++i)
    {
        unsigned long long int tmp = prev_prev + prev;
        prev_prev = prev;
        prev = tmp;
    }
    return(prev);
}

unsigned long long int fib_rec(int n)
{
    if(n<=1) return(n);
    else return(fib_rec(n-1) + fib_rec(n-2));
}

int main()
{
    std::cout << "45=" << fib_iter(45) << std::endl;
    std::cout << "0=" << fib_iter(0) << std::endl;
    std::cout << "50=" << fib_iter(50) << std::endl;
    std::cout << "100=" << fib_iter(100) << std::endl;
    
}
