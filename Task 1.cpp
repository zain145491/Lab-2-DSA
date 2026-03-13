#include <iostream>
using namespace std;
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() override 
    {
        return 3.14 * r * r;
    }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double length, double width) : l(length), w(width) {}
    double area() override 
    {
        return l * w;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);

    for (int i = 0; i < 2; i++) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() << endl;
        delete shapes[i];
    }
    return 0;
}