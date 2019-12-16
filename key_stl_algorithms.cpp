//
//  key_stl_algorithms.cpp
//  
//
//  Created by Jai Vrat Singh on 16/12/19.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <random> // for uniform_int_distribution function
#include <vector>


void printContents(std::vector<int>& v)
{
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main()
{
    // Initializing of uniform_int_distribution class
    std::uniform_int_distribution<int> distribution(1, 100);
    
    // Here default_random_engine object
    // is used as source of randomness
    // We can give seed also to default_random_engine
    // if psuedorandom numbers are required
    std::default_random_engine generator;
    
    std::vector<int> v;
     for (int i = 0; i < 20; ++i) {
         // using operator() function
         // to give random values
         int number = distribution(generator);
         v.push_back(number);
     }
    //Print contentsd
    printContents(v);
    
    std::sort(v.begin(), v.end());
    
    printContents(v);
    
    //binary search
    bool found =  binary_search( v.begin(), v.end(), 81 );
    std::cout << "Found 81:" << found << std::endl;
    
    found =  binary_search( v.begin(), v.end(), 45 );
    std::cout << "Found 45:" << found << std::endl;
    
    //std::lower_bound: Returns first element that is not less than (i.e. greater or equal to) value, or last if no such element is found.
    int searchThis = 80;
    std::vector<int>::iterator iter = std::lower_bound(v.begin(), v.end(), 80);
    if(iter != v.end())
    {
        std::cout << "Coudn't find" << searchThis <<  std::endl;
    } else {
        std::cout << "Found" << *iter << std::endl;
    }
    
    searchThis = 81;
    iter = std::lower_bound(v.begin(), v.end(), 80);
    if(iter == v.end())
    {
        std::cout << "Coudn't find" << searchThis <<  std::endl;
    } else {
        std::cout << "Found" << *iter << std::endl;
    }
}

