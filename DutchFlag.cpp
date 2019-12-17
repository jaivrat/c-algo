//
//  DutchFlag.cpp
//  
//
//  Created by Jai Vrat Singh on 17/12/19.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

void printContents(std::vector<int>& v, const char* sep= " ")
{
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, sep));
    std::cout << std::endl;
}

void swap(std::vector<int> v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void DutchFlagPartition(int pivot_index, std::vector<int>&v)
{
    int pivot_value = v[pivot_index];
    //invariants as in book: s: smaller, e: equal; l: larger
    //we maintain invariants that
    // 1. 0:s-1 are smaller than pivot
    // 2. s:e-1 are equal to pivot
    // 3. e:l-1 are unclassified
    // 4. l:last are top (larger)
    // the boundaries s, and e move forawrd, l moves back till e and l bang on(problem solved)
    int s = 0; int e = 0; int l=v.size();

    std::cout << "IN --" <<"\n";
    printContents(v, ",");
    while(e < l)
    {
        if(v[e] < pivot_value){
            swap(v, e, s);
            printContents(v, ",");
            s = s + 1;
            e = e + 1;
        } else if(v[e] == pivot_value) {
            e = e + 1;
        } else {
            l = l - 1;
            swap(v,e,l);
            printContents(v, ",");
        }
    }
    
    std::cout << "IN --" <<"\n";
}

int main()
{
    int a[] = {2,1,4,5,1,1,1,5,7,8,9,2,3,5,7,1,6,7,9,7};//20
    
    std::vector<int> v(a, a+20);
    
    printContents(v, ",");
    
    DutchFlagPartition(4, v);
    
    printContents(v, ",");
}
