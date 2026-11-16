#include <iostream>
using namespace std;

class Shape
{
protected:
    float r, l, w, b, h;

public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void area()
    {
        r = 5;
        cout << "Area of circle: " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area()
    {
        l = 10;
        w = 6;
        cout << "Area of rectangle: " << l * w << endl;
    }
};

class Triangle : public Shape
{
public:
    void area()
    {
        b = 2;
        h = 3;
        cout << "Area of triangle: " << 0.5 * b * h << endl;
    }
};

int main()
{
    Circle obj1;
    obj1.area();

    Rectangle obj2;
    obj2.area();

    Triangle obj3;
    obj3.area();

    return 0;
}
