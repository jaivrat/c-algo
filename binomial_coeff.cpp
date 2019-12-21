//
//  binomial_coeff.cpp
//  
//
//

#include <stdio.h>
#include <iostream>

unsigned long long binomial_coeff(int n, int k)
{
    if(k==n || k==0) return(1);
    else return(binomial_coeff(n-1, k) + binomial_coeff(n-1, k-1));
}


unsigned long long binomial_coeff_memo(int n, int k, bool first=true)
{
    int memo[n+1][k+1];
    memset(memo, 0, (n+1) * (k+1) * sizeof(unsigned long long));
    
    for(int n_val=0; n_val <= n; ++n_val)
    {
        for(int k_val =0; k_val <= min(k,n_val) ; ++k_val)
        {
            //
            if(k_val == 0 || n_val)
            
        }
    }
    
    
    else return(binomial_coeff_memo(n-1, k, false) + binomial_coeff_memo(n-1, k-1, false));
}

int main()
{
    int n = 10, k = 2;
    std::cout << "non memo :   n=" << n << "  k=" << k << " :" <<binomial_coeff(n,k) << std::endl;
    std::cout << "    memo :    n=" << n << "  k=" << k << " :" <<binomial_coeff_memo(n,k) << std::endl;
}
