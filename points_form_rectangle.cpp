//
//  points_form_rectangle.cpp
//  
//
//
//  Algorithm to check if points form rectangle
//
//  Created by Jai Vrat Singh on 15/12/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <math.h>
#include <map>
#include <vector>

//to represent a rectangle
struct Point
{
    double x;
    double y;
    Point(double xin, double yin):x(xin),y(yin){}
};

double getSlope(const Point&p1, const Point&p2)
{
    double slope;
    if(p1.x - p2.x == 0){
        slope = std::numeric_limits<double>::infinity();
    } else {
        slope = (p1.y - p2.y)/(p1.x - p2.x);
    }
    return(slope);
}

bool checkPerpendicular(double slope1, double slope2)
{
   if(slope1 == std::numeric_limits<double>::infinity())
    {
        return(abs(slope2 - 0.00) < 1e-8);
    } else if (slope2 == std::numeric_limits<double>::infinity())
    {
        return(abs(slope1 -0.0)< 1e-8);
    } else {
        return(abs(slope1 * slope2 - (-1.0)) < 1e-8);
    }
}

//Checks if points make rectangle: let us not assume they are in order (clockwise or anti-clockwise)
bool formRectangle(const std::vector<Point>& points)
{
    //let us form an order
    double slope1 = getSlope(points[0], points[1]);
    double slope2 = getSlope(points[1], points[2]);
    bool p1  = checkPerpendicular(getSlope(points[0], points[1]),
                                 getSlope(points[1], points[2]));
    bool p2  = checkPerpendicular(getSlope(points[0], points[3]),
                                getSlope(points[3], points[2]));
    return(p1 && p2);
}


int main()
{
    std::vector<Point> points1;
    points1.push_back(Point(1,1));
    points1.push_back(Point(5,1));
    points1.push_back(Point(5,5));
    points1.push_back(Point(1,5));
    std::cout << "Forms rectangle ?" << formRectangle(points1) << std::endl;
    
    
    std::vector<Point> points2;
    points2.push_back(Point(1,1.01));
    points2.push_back(Point(5,1));
    points2.push_back(Point(5,5));
    points2.push_back(Point(1,5));
    std::cout << "Forms rectangle ?" << formRectangle(points2) << std::endl;
    
    //tilted square
    std::vector<Point> points3;
    points3.push_back(Point(5,5));
    points3.push_back(Point(5.0 + 3.0/sqrt(2),5 + 3.0/sqrt(2)));
    points3.push_back(Point(5.0 ,5.0 + 2 * 3.0/sqrt(2)));
    points3.push_back(Point(5.0 - 3.0/sqrt(2),5 + 3.0/sqrt(2)));
    for(std::vector<Point>::const_iterator iter = points3.begin(); iter != points3.end(); ++iter)
    {
        std::cout << "(x,y)=(" << iter->x << "," << iter->y << ")" << std::endl;
    }
    std::cout << "Forms rectangle ?" << formRectangle(points3) << std::endl;

    return(0);
}
