//
//  quick_sort.cpp
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

void swap(std::vector<int>& v, int i, int j)
{
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

//This moves v[i] to correct position
int partition(std::vector<int>& v, int start, int end)
{
    if(start <0 || end > v.size() -1)
    {
        std::cerr << "start=" << start << "  end="
        << end << std::endl;
        
    }
    //std::cout << "In partition\n";
    //printContents(v);
    int pivot = start;
    int i     = start;
    for(int j = start+1; j <= end; j = j + 1)
    {
        if(v[j] <= v[pivot])
        {
            i = i + 1;
            swap(v, i, j);
            //printContents(v);
        }
    }
    //after this loop, i points to pivot pos. swap with pivot
    swap(v, pivot, i);
    //printContents(v);
    //std::cout << "In partition\n";
    return(i);
}

void quick_sort(std::vector<int>& v, int start, int end)
{
    if(start>=end) return;
    else
    {
        int place = partition(v, start, end);
        std::cout << "place = " << place << std::endl;
        quick_sort(v,0, place);
        quick_sort(v,place+1, end);
    }
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
    for (int i = 0; i < 500; ++i) {
         // using operator() function
         // to give random values
         int number = distribution(generator);
         v.push_back(number);
    }
    
    //Print contents
    printContents(v);
    
    //int place = partition( v, 0, v.size()-1);
    //std::cout << "Place=" << place << "\n";
    //printContents(v);
    
    quick_sort(v, 0, v.size()-1);
    std::cout << "After Sorting\n";
    printContents(v);

}

