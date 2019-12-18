//
//  max_drawdown.cpp
//  
//
//  Created by Jai Vrat Singh
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <numeric>

template<typename T>
void printContents(std::vector<T>& v, const char* sep= " ")
{
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, sep));
    std::cout << std::endl;
}

double max_drawdown(const std::vector<double>& v)
{
    double peak_sofar = *v.begin();
    double max_ddn_so_far = 0.0;
    for(std::vector<double>::const_iterator iter = ++v.begin(); iter != v.end(); ++iter)
    {
        double thisddn = (*iter)/peak_sofar - 1.0;
        
        if(thisddn < max_ddn_so_far)
        {
            max_ddn_so_far = thisddn;
        }
        
        if(peak_sofar < *iter)
        {
            peak_sofar = *iter;
        }
    }
    return(max_ddn_so_far); //bad to return vectors, but lets focus on main logic here
}

int main()
{
    double p[] = {30, 40.0, 37.0, 38.0, 31.0, 37.5, 28.0, 33.0, 31.0, 37.5, 40, 40.5, 33.0, 30.0};
    std::vector<double> v;
    v.insert(v.begin(), p, p + 14);
    printContents(v);
    
    //
    double max_ddn = max_drawdown(v);
    std::cout << "Max drawdown = " <<max_ddn << std::endl;
}
