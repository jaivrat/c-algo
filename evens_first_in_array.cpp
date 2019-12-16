//
//  evens_first_in_array.cpp
//  
//  Given input array, reorder to have evens first.
//  Created by Jai Vrat Singh on 16/12/19.
//

#include <stdio.h>
#include <iostream>

int* reorder(int* a, unsigned int size)
{
    int i = 0;
    int j = size-1;
    while(j>i)
    {
        if(a[j] % 2 == 0) //even found
        {
            while(a[i] %2 == 0 && (i < j)) ++i;
            if(i >= j) break;
            //std::cout << "Swapping " <<a[j] << ":" <<a[i];
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i = i +1;
        }
        j = j -1;
    }
    return(a);
}

void printArray(int * a, int size)
{
    std::cout << "{" ;
    for(int i=0; i < size; ++i)
        std::cout << a[i] << " ";
    
    std::cout << "}" << std::endl ;
}

int main()
{
    
    std::cout << 11%2 << "\n";
    
    int a1[] = {1 , 2, 3, 4, 5, 6, 7};
    int a2[] = {2,4, 6, 8, 1, 3, 5, 7};
    int a3[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int a4[] = {4, 6, 8, 10, 20, 30,40};
    int a5[] = {9,5,7,13, 1, 3, 5, 7};
    
    std::cout << std::endl;
    std::cout << "a1:" << std::endl;
    printArray(a1, 7);
    printArray(reorder(a1, 7), 7);
    
    std::cout << std::endl;
    std::cout << "a2:" << std::endl;
    printArray(a2, 7);
    printArray(reorder(a2, 7), 7);
    
    
    std::cout << std::endl;
    std::cout << "a3:" << std::endl;
    printArray(a3, 7);
    printArray(reorder(a3, 7), 7);
    
    std::cout << std::endl;
    std::cout << "a4:" << std::endl;
    printArray(a4, 7);
    printArray(reorder(a4, 7), 7);
    
    std::cout << std::endl;
    std::cout << "a5:" << std::endl;
    printArray(a5, 7);
    printArray(reorder(a5, 7), 7);
}
