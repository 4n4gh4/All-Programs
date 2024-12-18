#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Default constructor
    Time() : hours(0), minutes(0) {}

    // Parameterized constructor
    Time(int h, int m) : hours(h), minutes(m) {}

    // Overloading the == operator to compare two time objects
    bool operator==(const Time &t) const {
        return (hours == t.hours && minutes == t.minutes);
    }

    void display() const {
        cout << hours << " hours and " << minutes << " minutes" << endl;
    }
};

int main() {

    Time time1(3, 30);
    Time time2(3, 30);

    cout << "Time 1: ";
    time1.display();
    cout << "Time 2: ";
    time2.display();

    // Comparing time objects
    if (time1 == time2) {
        cout << "Time 1 and Time 2 are equal." << endl;
    } else {
        cout << "Time 1 and Time 2 are not equal." << endl;
    }

    return 0;
}
