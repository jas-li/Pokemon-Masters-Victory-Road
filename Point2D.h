#ifndef Point2D_h
#define Point2D_h

#include <iostream>
#include "Vector2D.h"

using namespace std;

class Point2D {
    public:
        Point2D();
        Point2D(double in_x, double in_y);
        double x;
        double y;
};

double GetDistanceBetween(Point2D p1, Point2D p2);

ostream& operator<<(ostream& os, const Point2D& pt);

Point2D operator+(const Point2D& pt, const Vector2D& vec);

Vector2D operator-(const Point2D& p1, const Point2D& p2);

#endif