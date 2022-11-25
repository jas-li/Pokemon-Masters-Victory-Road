#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"

using namespace std;

int main() {
    Point2D p1(3.6, 6.7);
    cout << p1 << endl;

    Vector2D v1(1.3, 3.1);
    cout << v1 << endl;

    Point2D p2 = p1 + v1;
    cout << "p2: " << p2 << endl;

    Point2D p3(4.4, 8.1);
    cout << "p3: " <<  p3 << endl;
    cout << "subtract " << p2 - p3 << endl;

    cout << "distance " << GetDistanceBetween(p1, p2) << endl;

    cout << "multply: " << v1 << " * 4 = " << v1*4 << endl;
    cout << "divide: " << v1 << " / 4 = " << v1/4 << endl;

    GameObject obj(p2, 1, 'd');
    obj.ShowStatus();
    return 0;
}