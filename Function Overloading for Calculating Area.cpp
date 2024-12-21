#include <iostream>
#include <cmath>
using namespace std;
class AreaCalculator {
public:
    double area(double radius) {
        return M_PI * radius * radius;
    }

    double area(double length, double breadth) {
        return length * breadth;
    }

    double area(double base, double height, int triangle) {
        return 0.5 * base * height;
    }
};
int main() {
    AreaCalculator calculator;

    cout << "Area of Circle (radius = 5): " << calculator.area(5.0) << endl;
    cout << "Area of Rectangle (length = 4, breadth = 6): " << calculator.area(4.0, 6.0) << endl;
    cout << "Area of Triangle (base = 3, height = 4): " << calculator.area(3.0, 4.0, 1) << endl;

    return 0;
}