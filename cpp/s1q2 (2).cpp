#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coeffs; //this is a data type that allocates a dynamic array

public:
    // Default constructor
    Polynomial() : coeffs(3, 0) {}

    // Parameterized constructor
    Polynomial(const vector<int> &coefficients) {
        coeffs = coefficients;
    }

    // adding two polynomials
    Polynomial add(const Polynomial &p) const {
        vector<int> result(coeffs.size(), 0);

        for (int i = 0; i < coeffs.size(); i++) {
            result[i] = coeffs[i] + p.coeffs[i];
        }

        return Polynomial(result);
    }

    // Overload: adding constant to polynomial
    Polynomial add(int constant) const {
        vector<int> result = coeffs;
        if (!result.empty()) {
            result[0] += constant;
        }
        return Polynomial(result);
    }

    // subtracting polynomials
    Polynomial subtract(const Polynomial &p) const {
        vector<int> result(coeffs.size(), 0);

        for (int i = 0; i < coeffs.size(); i++) {
            result[i] = coeffs[i] - p.coeffs[i];
        }

        return Polynomial(result);
    }

    // Overload: subtracting constant from polynomial
    Polynomial subtract(int constant) const {
        vector<int> result = coeffs;
        if (!result.empty()) {
            result[0] -= constant;
        }
        return Polynomial(result);
    }

    // x evaluation
    int evaluate(int x) const {
        int result = 0;
        int power = 1;

        for (int coeff : coeffs) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

    void display() const {
        for (int i = coeffs.size() - 1; i >= 0; i--) {
            if (coeffs[i] != 0) {
                cout << coeffs[i];
                if (i > 0) {
                    cout << "x^" << i;
                }
                if (i > 0 && coeffs[i - 1] >= 0) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
     // Default constructor
    cout << "Default constructor: " << endl;
    Polynomial def;
    def.display();
    cout << endl;

    // Parameterized constructor
    cout << "Parameterized constructor: " << endl;
    vector<int> coeffs = {1, 2, 3};  // Represents 1 + 2x + 3x^2
    Polynomial poly1(coeffs);
    poly1.display();
    cout << endl;

    // Add two polynomials
    cout << "Adding polynomials: " << endl;
    vector<int> coeffs2 = {4, 0, 2};  // Represents 4 + 0x + 2x^2
    Polynomial poly2(coeffs2);
    Polynomial result = poly1.add(poly2);
    result.display();
    cout << endl;

    // Subtract two polynomials
    cout << "Subtracting polynomials: " << endl;
    Polynomial result2 = poly1.subtract(poly2);
    result2.display();
    cout << endl;

    // Evaluate polynomial for a given x
    int x;
    cout<<"Enter value of x: ";
    cin>>x;

    cout << "Evaluating polynomial for x = "<<x<< endl;
    int value = poly1.evaluate(2);
    cout << "Result: " << value << endl;

    return 0;
}
