//
//  mult_arbitraylarge_integers.cpp
//  
//
//  Created by Jai Vrat Singh on 18/12/19.
//

#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>

template<typename T>
void printContents(const std::vector<T>& v, const char* sep= " ")
{
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, sep));
    std::cout << std::endl;
}

std::vector<int> multiply_single_digit(const std::vector<int>& v, int by)
{
    std::vector<int> result;
    result.reserve(v.size()+1);
    int carry = 0;
    for(int i = v.size()-1; i >= 0; --i)
    {
        int res_ = v[i] * by + carry;
        result.insert(result.begin(), res_ % 10);
        carry = res_/10;
    }
    if(carry>0)
    {
        result.insert(result.begin(), carry);
    }
    return(result);
}

std::vector<int> multiply_two_vec(const std::vector<int>& v1, const std::vector<int>& v2)
{
    std::vector< std::vector<int> > matrix;
    int i = 0;
    int max_size = 0;
    std::cerr << "Done 1" << std::endl;
    for(std::vector<int>::const_reverse_iterator riter2= v2.rbegin();
        riter2 != v2.rend(); ++riter2)
    {
        std::vector<int> _result = multiply_single_digit(v1, *riter2);
        for(int j=0; j<i; ++j) _result.push_back(0);
        i = i + 1;

        if(max_size < _result.size()) max_size = _result.size();
        matrix.push_back(_result);
        printContents(_result);
    }
    
    std::cout << "Done 2" << std::endl;
    
    std::vector<int> result;
    int column = max_size;
    int carry = 0;
    while(column >= 1)
    {
        int _sum = 0;
        for(std::vector<std::vector<int> >::const_iterator it = matrix.begin(); it != matrix.end(); ++it)
        {
            int pos_access = column - (max_size - it->size()) -1;
            if(pos_access >= 0)
            {
                _sum += it->operator[](pos_access);
            }
        }
        
        std::cout << "sum = " << _sum << "\n";
        _sum += carry;
        std::cout << "sum + carry = " << _sum << "\n";
        result.push_back(_sum % 10);
        carry = _sum - _sum % 10;
        std::cout << "carry = " << carry << "\n";
        --column;
    }
    
    while(carry >0)
    {
        result.insert(result.begin(), carry % 10);
        carry = (carry - carry % 10)/10;
    }
    
    return(result);
}

int main()
{
    std::vector<int> v;
    v.push_back(9); v.push_back(0); v.push_back(5);
    printContents(multiply_single_digit(v, 8));
    

    printContents(multiply_two_vec(v, v));
    
}
