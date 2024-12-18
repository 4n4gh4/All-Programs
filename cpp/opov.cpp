#include <iostream>
using namespace std;

class complex {
private:
    int real;
    int img;

public:
    complex(int r = 0, int i = 0) : real(r), img(i) {}

    complex operator+(complex const &other) {
        return complex(real + other.real, img + other.img);
    }

    void print() const {
        cout << real << "+i" << img << "\n";
    }
}; 

int main() {
    complex c1(2, 3);
    complex c2(3, 4);

    c1.print();
    c2.print();
    complex c3 = c1 + c2;
    c3.print();

    return 0;
}
