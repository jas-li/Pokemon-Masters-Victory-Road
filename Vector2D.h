#ifndef Vector2D_h
#define Vector2D_h

#include <iostream>

using namespace std;

class Vector2D {
    public:
        Vector2D();
        Vector2D(double in_x, double in_y);
        double x;
        double y;
};

Vector2D operator*(const Vector2D& vec, double d);

Vector2D operator/(const Vector2D& vec, double d);

ostream& operator<<(ostream& os, const Vector2D& vec);

#endif