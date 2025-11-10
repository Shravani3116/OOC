#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void area() {
        cout << "Area of shape" << endl;
    }
};


class Circle : public Shape {
public:
    void area() override {
        int radius = 5;
        float result = 3.14 * radius * radius;
        cout << "Area of circle: " << result << endl;
    }
};


class Rectangle : public Shape {
public:
    void area() override {
        int length = 4, width = 6;
        int result = length * width;
        cout << "Area of rectangle: " << result << endl;
    }
};


int main() {
    Shape* shape;

    Circle c;
    Rectangle r;

    shape = &c;
    shape->area(); 

    shape = &r;
    shape->area();  

    return 0;
}

