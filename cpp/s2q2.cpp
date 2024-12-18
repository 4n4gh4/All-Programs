#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() : day(1), month(1), year(2000) {}

    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // formats date as string
    string toString() const {
        return to_string(day) + '/' + to_string(month) + '/' + to_string(year);
    }

    void display() const {
        cout << toString() << endl;
    }
};

int main() {

    Date myDate(15, 8, 2024);

    cout << "The date is: ";
    myDate.display();

    return 0;
}
