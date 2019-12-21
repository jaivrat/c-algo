//
//  number_combination.cpp
//  
//


#include <stdio.h>
#include <iostream>


int num_permutation(int score)
{
    //either last one is 2 or not 2
    if(score == 2 || score == 3 || score == 7)
    {
        return(1);
    } else if(score <= 0){
        return(0);
    }
    else {
        return( num_permutation(score - 2) +  num_permutation(score - 3) + num_permutation(score - 7));
    }
}


//Stack issue - correct ;later
int num_combination(int score, int stacklen = 0)
{
    std::cout << "debug stacklen =" << stacklen << "\n";
    //either last one is 2 or not 2
    if(score == 2 || score == 3 || score == 7)
    {
        return(1);
    } else if(score <=0){
        return(0);
    }
    else {
        //loop for 2
        int res = 0;
        for(int i = 0; i <= score/2; i = i + 2)
        {
            for(int j = 0; j <= score/3; j = j + 3)
            {
                for(int k = 0; k <= score/7; k = k + 7)
                {
                    stacklen = stacklen + 1;
                    res +=  num_combination(score - 2*i - 3*j - 7*k, stacklen);
                }
            }
        }
            
        return(res);
    }
}

int main()
{
    for(int i=0; i <= 12; ++i)
    {
        std::cout << "Score : " << i << " -->" <<num_permutation(i) << std::endl;
    }
    
    std::cout << "-------------Combinations---------------" << std::endl;
    for(int i=0; i <= 4; ++i)
    {
        std::cout << "Score : " << i << " -->" <<num_combination(i) << std::endl;
    }
}


