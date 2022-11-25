#include "Point2D.h"
#include <cmath>

using namespace std;

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

Vector2D operator*(const Vector2D& vec, double d) {
    double x = vec.x * d; 
    double y = vec.y * d;
    Vector2D newVec(x, y);
    return newVec;
}

Vector2D operator/(const Vector2D& vec, double d) {
    if(d == 0) {
        Vector2D newVec(vec.x, vec.y);
        return newVec;
    }
    double x = vec.x / d;
    double y = vec.y / d;
    Vector2D newVec(x, y);
    return newVec;
}

ostream& operator<<(ostream& os, const Vector2D& vec) {
    os << '<' << vec.x << ", " << vec.y << '>';
    return os;
}