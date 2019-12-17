//
//  increment_big_digit.cpp
//  
//
//  Created by Jai Vrat Singh on 17/12/19.
//

#include <stdio.h>
#include <vector>
#include <iostream>

std::vector<int>& incr_by_one(std::vector<int>& v)
{
    int carry = 1;
    for(int i = v.size()-1; i>= 0; --i)
    {
        int sm = v[i] + carry;
        v[i]   = sm % 10;
        carry  = (sm > 9)?1:0;
    }
    
    if(carry >= 1)
    {
        int arr[] = {1};
        std::vector<int>  vec;
        vec.reserve(1 + v.size());
        v.insert(v.begin(),1);
    }
    
    return(v);
}

void printContents(std::vector<int>& v)
{
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << std::endl;
}

int main()
{
    //(987743009100) to be incremented by 1
    //std::vector<int> v;
    //v.push_back(9);v.push_back(9);v.push_back(9);
    
    //std::vector<int> v;
    //v.push_back(9);v.push_back(1);v.push_back(1);
    
    std::vector<int> v;
    v.push_back(1);
    
    incr_by_one(v);
    printContents(v);
}
