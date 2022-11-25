#include "Point2D.h"
#include <cmath>

using namespace std;

Point2D::Point2D() {
    x = 0;
    y = 0;
}

Point2D::Point2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

ostream& operator<<(ostream& os, const Point2D& pt) {
    os << '(' << pt.x << ", " << pt.y << ')';
    return os;
}

Point2D operator+(const Point2D& pt, const Vector2D& vec) {
    double x = pt.x + vec.x;
    double y = pt.y + vec.y;
    Point2D newPt(x, y);
    return newPt;
}

Vector2D operator-(const Point2D& p1, const Point2D& p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    Vector2D vec(x, y);
    return vec;
}
