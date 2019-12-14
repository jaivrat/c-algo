//
//  uniform_random.cpp
//  
//
//  Created by Jai Vrat Singh on 14/12/19.
//Generate random uniform number [low, high] assuming
//you can generate randomly a coin toss(0/1) and nothing else
//1. suppose you are to generate numbers from binary repr 0 to
//   111, ie numerical 0 to 7, ie 2^(3) -1 , it is easy to do
//   - do 3 tosses and concatenate the bits. 000, 100, 010, 001, 110, 101, 011, 111. You get the numbers.
//  But you may be given to generate numbers from 0-9 say. then
//  you can generate smallest till i number such that 2^i - 1 >= 9
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <math.h>
#include <map>

int get_toss()
{
    // Use current time as seed for random generator
    return(double(rand())/(RAND_MAX + 1.0) > 0.5? 1:0);
}

int uniform_random(int low, int high)
{
    //set bounds of generation from 0 to high-low.
    int N = high - low + 1; //[0, 1, ... (N-1)]
    int res = 0;
    
    while(true)
    { //we keep on trying till we get a number in range to N
        res = 0;
        for(int i = 0; pow(2, i) < N; i++)
        {
            res = (res << 1)|get_toss();
        }
        
        if(res <= N-1)//we need only till N-1
        {
            break;
        }
    }
    return(low + res);
}


int main()
{
    srand(time(0));
   // for(int i = 0 ; i < 100; ++i)
     //   std::cout << "Rand= " << get_toss();
    
    std::cout <<  uniform_random(10, 20) << std::endl;
    
    std::map<int,int> m;
    for(int i = 1; i <= 10000; i++)
    {
        int val = uniform_random(10, 20);
        std::map<int,int>::iterator it = m.find(val);
        if(it != m.end())
        {
            m[val] += 1;
        } else {
            m.insert(std::make_pair<int,int>(val,1));
        }
    }
    
    struct Sum
    {
        int sum;
        Sum(): sum(0){ }
        void operator()(const std::pair<int,int>& p) { sum += p.second; }
    };
    
    
    Sum s = std::for_each(m.begin(), m.end(), Sum());
    
    std::map<int,int>::const_iterator iter;
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        std::cout << iter->first << ":" << double(iter->second)/s.sum << std::endl;
    }
    
    
    

}
