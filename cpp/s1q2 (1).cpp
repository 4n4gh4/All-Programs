#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    int x, y;

public:
    // Default constructor
    Vector() {
        x = 0;
        y = 0;
    }

    // Parameterized constructor
    Vector(int a, int b) {
        x = a;
        y = b;
    }

    // Function to calculate the dot product
    int dotProduct(const Vector &v) const {
        return (x * v.x + y * v.y);
    }

    // Overloaded dotProduct function for scalar multiplication
    int dotProduct(int scalar) const {
        return (x * scalar + y * scalar);
    }

    // Function to calculate the cross product (returns scalar value)
    int crossProduct(const Vector &v) const {
        return (x * v.y - y * v.x);
    }

    // Overloaded crossProduct function for scalar multiplication
    int crossProduct(int scalar) const {
        return (x * scalar - y * scalar);
    }

    // Function to calculate the magnitude
    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    // Overloaded magnitude function for scalar multiplication
    double magnitude(int scalar) const {
        return sqrt((x * scalar) * (x * scalar) + (y * scalar) * (y * scalar));
    }

    // Function to display the vector
    void display() const {
        cout << "Vector: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int scalar;

    // Default constructor
    cout << "Default constructor: " << endl;
    Vector vec1;
    vec1.display();
    cout << "Magnitude: " << vec1.magnitude() << endl;
    cout << endl;

    // Parameterized constructor
    cout << "Parameterized constructor: " << endl;
    Vector vec2(3, 4);
    vec2.display();
    cout << "Magnitude: " << vec2.magnitude() << endl;
    cout << endl;

    // Dot product and cross product (normal)
    cout << "Dot and Cross Product operations: " << endl;
    Vector vec3(2, 5);
    Vector vec4(3, 7);
    vec3.display();
    vec4.display();
    cout << "Dot Product: " << vec3.dotProduct(vec4) << endl;
    cout << "Cross Product: " << vec3.crossProduct(vec4) << endl;
    cout << endl;

    // Scalar operations (Overloaded functions)
    cout << "Scalar Operations: " << endl;
    cout<<"Enter the scalar value: ";
    cin>>scalar;
    cout << "Dot Product with scalar " << scalar << ": " << vec3.dotProduct(scalar) << endl;
    cout << "Cross Product with scalar " << scalar << ": " << vec3.crossProduct(scalar) << endl;
    cout << "Magnitude with scalar " << scalar << ": " << vec3.magnitude(scalar) << endl;

    return 0;
}
