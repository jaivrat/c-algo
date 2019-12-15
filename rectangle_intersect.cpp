//
//  rectangle_intersect.cpp
//  
//  Algorithm to check intersection of two rectangles.
//  - if they intersect, return rectangle of intersection
//
//  Created by Jai Vrat Singh on 15/12/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <math.h>
#include <map>


//to represent a rectangle
struct Point
{
    double x;
    double y;
    Point(double xin, double yin):x(xin),y(yin){}
};

struct Rectangle{
    Point p;
    double length;
    double width;
    Rectangle(const Point& pin, double l, double w):p(pin), length(l),width(w){}
};


//Checks intersection: returns true if not intersecting
bool checkNoIntersection(const Rectangle& r1, const Rectangle& r2)
{
    //check which rectangle is nearest to y axis
    const Rectangle & r_near = (r1.p.x<= r2.p.x)?r1:r2;
    const Rectangle & r_far  = (r1.p.x > r2.p.x)?r1:r2;
    
    //check which rectangle is nearest to x axis
    const Rectangle & r_near_x = (r1.p.y - r1.width <= r2.p.y - r2.width)?r1:r2;
    const Rectangle & r_far_x  = (r1.p.y - r1.width > r2.p.y - r2.width)?r1:r2;
    
    //These mean not intersecting
    bool x_criteria = r_far.p.x > (r_near.p.x + r_near.length);
    bool y_criteria = (r_near_x.p.y < r_far_x.p.y- r_far_x.width);
    
    return(x_criteria || y_criteria);
}


int main()
{
    Rectangle r1(Point(1,3), 4, 2);
    Rectangle r2(Point(2,5), 8, 1.9);
    Rectangle r3(Point(2,5), 8, 3);//r3 intersects with r1
    Rectangle r4(Point(2,5), 8, 10);//r4 intersects with r1,r2,r3
    Rectangle r5(Point(-10,10), 1000, 1000);//r5 contains all
    
    std::cout << "Check if no intersection r1, r2 " << checkNoIntersection(r1, r2) << "\n";
     std::cout << "Check if no intersection r1, r3 " << checkNoIntersection(r1, r3)<< "\n";
    std::cout << "Check if no intersection r1, r4 " << checkNoIntersection(r1, r4)<< "\n";
    std::cout << "Check if no intersection r2, r4 " << checkNoIntersection(r2, r4)<< "\n";
    std::cout << "Check if no intersection r3, r4 " << checkNoIntersection(r3, r4)<< "\n";
    
    std::cout << "--------------------------" << std::endl;
    std::cout << "Check if no intersection r5 " << checkNoIntersection(r5, r1)<< "\n";
}
