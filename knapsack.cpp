//
//  knapsack.cpp
//  
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

struct Clock
{
    double price;
    double weight;
    Clock(double _price, double _weight): price(_price),weight(_weight){}
};

double value_subset(int from,
                    int to_inclusive, const std::vector<Clock>& v)
{
    double res = 0.0;
    for(int i=1; i<=to_inclusive; ++i) res+= v[i].price;
    return(res);
}

double max_val_theft(const std::vector<Clock>& v, int to_inclusive, double capacity)
{
    if(to_inclusive < 0)
        return(0.0);
    //std::cerr << "checking to_inclusive=" << to_inclusive << std::endl;
    if(v[to_inclusive].weight > capacity)
        return(max_val_theft(v, to_inclusive-1, capacity));
    else {
        double incl = max_val_theft(v,  to_inclusive-1, capacity - v[to_inclusive].weight) + v[to_inclusive].price;
        double excl = max_val_theft(v,  to_inclusive-1, capacity);
        return(std::max(incl, excl));
    }
}

int main()
{
    std::vector<Clock> v;
    
    v.push_back(Clock(65,20));
    v.push_back(Clock(35,8));
    v.push_back(Clock(245,60));
    v.push_back(Clock(195,55));
    v.push_back(Clock(65,40));
    v.push_back(Clock(150,70));
    v.push_back(Clock(275,85));
    v.push_back(Clock(155,25));
    v.push_back(Clock(120,30));
    v.push_back(Clock(320,65));
    v.push_back(Clock(75,75));
    v.push_back(Clock(40,10));
    v.push_back(Clock(200,95));
    v.push_back(Clock(100,50));
    v.push_back(Clock(220,40));
    v.push_back(Clock(99,10));

    /////////////////////////////////
    double val = max_val_theft(v, v.size()-1, 30.0);
    
    std::cerr << "val=" << val << std::endl;
    
    v.clear();
    v.push_back(Clock(60,5));
    v.push_back(Clock(50,3));
    v.push_back(Clock(70,4));
    v.push_back(Clock(195,55));
    v.push_back(Clock(30,2));
    
    val = max_val_theft(v, v.size()-1, 5.0);
    std::cerr << "val=" << val << std::endl;
}
