#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;


#include <iostream>
#include <math.h>
 
int IsPointInBoundingBox(float x1, float y1, float x2, float y2, float px, float py)
{
    float left, top, right, bottom; // Bounding Box For Line Segment
    // For Bounding Box
    if(x1 < x2)
    {
        left = x1;
        right = x2;
    }
    else
    {
        left = x2;
        right = x1;
    }
    if(y1 < y2)
    {
        top = y1;
        bottom = y2;
    }
    else
    {
        top = y1;
        bottom = y2;
    }
 
    if( (px+0.01) >= left && (px-0.01) <= right && 
            (py+0.01) >= top && (py-0.01) <= bottom )
    {
        return 1;
    }
    else
        return 0;
}
 
int LineIntersection(float l1x1, float l1y1, float l1x2, float l1y2,
                            float l2x1, float l2y1, float l2x2, float l2y2,
                            float *m1, float *c1, float *m2, float *c2,
                            float* intersection_X, float* intersection_Y)
{
    float dx, dy;
    dx = l1x2 - l1x1;
    dy = l1y2 - l1y1;
 
    *m1 = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    *c1 = l1y1 - *m1 * l1x1; // which is same as y2 - slope * x2
 
    dx = l2x2 - l2x1;
    dy = l2y2 - l2y1;
 
    *m2 = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    *c2 = l2y1 - *m2 * l2x1; // which is same as y2 - slope * x2
 
    if( (*m1 - *m2) == 0)
        return 0;
    else
    {
        *intersection_X = (*c2 - *c1) / (*m1 - *m2);
        *intersection_Y = *m1 * *intersection_X + *c1;
    }
}
 
int LineSegmentIntersection(float l1x1, float l1y1, float l1x2, float l1y2,
                            float l2x1, float l2y1, float l2x2, float l2y2,
                            float *m1, float *c1, float *m2, float *c2,
                            float* intersection_X, float* intersection_Y)
{
    float dx, dy;
 
    dx = l1x2 - l1x1;
    dy = l1y2 - l1y1;
 
    *m1 = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    *c1 = l1y1 - *m1 * l1x1; // which is same as y2 - slope * x2
 
    dx = l2x2 - l2x1;
    dy = l2y2 - l2y1;
 
    *m2 = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    *c2 = l2y1 - *m2 * l2x1; // which is same as y2 - slope * x2
 
    if( (*m1 - *m2) == 0)
        return 0;
    else
    {
        *intersection_X = (*c2 - *c1) / (*m1 - *m2);
        *intersection_Y = *m1 * *intersection_X + *c1;
    }
    if(IsPointInBoundingBox(l1x1, l1y1, l1x2, l1y2, *intersection_X, *intersection_Y) == 1 &&
        IsPointInBoundingBox(l2x1, l2y1, l2x2, l2y2, *intersection_X, *intersection_Y) == 1)
    {
        return 1;
    }
    else
        return 0;
}
 
 
int main()
{
    float m1, c1, m2, c2;
    float l1x1, l1y1, l1x2, l1y2;
    float l2x1, l2y1, l2x2, l2y2;
    float intersection_X, intersection_Y;
    int nRet;
 
    std::cout << "Program to find the intersection point of two line segments:\n";
 
    std::cout << "Enter Line1 - X1: ";
    std::cin >> l1x1;
 
    std::cout << "Enter Line1 - Y1: ";
    std::cin >> l1y1;
 
    std::cout << "Enter Line1 - X2: ";
    std::cin >> l1x2;
 
    std::cout << "Enter Line1 - Y2: ";
    std::cin >> l1y2;
 
    std::cout << "Enter Line2 - X1: ";
    std::cin >> l2x1;
 
    std::cout << "Enter Line2 - Y1: ";
    std::cin >> l2y1;
 
    std::cout << "Enter Line2 - X2: ";
    std::cin >> l2x2;
 
    std::cout << "Enter Line2 - Y2: ";
    std::cin >> l2y2;
 
    nRet = LineSegmentIntersection(l1x1, l1y1, l1x2, l1y2,
                            l2x1, l2y1, l2x2, l2y2,
                            &m1, &c1, &m2, &c2, &intersection_X, &intersection_Y);
 
    printf("Equation of line1: Y = %.2fX %c %.2f\n", m1, (c1 < 0) ? ' ' : '+',  c1);
    printf("Equation of line2: Y = %.2fX %c %.2f\n", m2, (c2 < 0) ? ' ' : '+',  c2);
 
    if(nRet == 0)
        printf("The two line segments do not intersect each other");
    else
        printf("The two line segments intersect each other at %.2f, %.2f", intersection_X, intersection_Y);
return 0;
}
