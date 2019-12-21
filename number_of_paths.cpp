//
//  number_of_paths.cpp
//  
//
//  Created by Jai Vrat Singh on 21/12/19.
//



#include <stdio.h>
#include <iostream>


int grid[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,1,0},
    {0,0,0,0,1,0,0,0},
    {1,0,1,0,0,1,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,1,0,1,0},
    {0,1,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0}
};
/*
int grid[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};
*/
int find_num_paths(int i, int j)
{
    int res =0;
    if(i > 7  || j > 7 || grid[i][j] == 1)
        res = 0;
    else if((i==7 && j==6) || (i==6 && j==7))
        res = 1;
    else
    {
        res = find_num_paths(i+1,j) + find_num_paths(i,j+1);
        return(res);
    }
    std::cout << "called.." << i << "," << j << ": " << res << std::endl;
    return(res);
}

int main()
{
    std::cout << find_num_paths(0,0);
}
