#include <iostream>
#include <string>
using namespace std;

class station {
    private:
        long sid;
        string sname;
        string place;
        float t;
        float h;
        float p;

    public:
        station(long sid, string sname, string place, float t, float h, float p)
            : sid(sid), sname(sname), place(place), t(t), h(h), p(p) {}

        void weather() {
            cout << "The weather station name is: " << sname << endl;
            cout << "The weather station location is: " << place << endl;
            cout << "The weather station ID is: " << sid << endl;
            cout << "The weather station temperature is: " << t << endl;
            cout << "The weather station humidity is: " << h << endl;
            cout << "The weather station pressure is: " << p << endl;
        }

        void t_check() {
            if (t > 15.0) {
                cout << "The temperature is greater than usual" << endl;
            } else if (t < 5.0) {
                cout << "The temperature is lesser than usual" << endl;
            } else {
                cout << "Moderate temperature" << endl;
            }
        }

        void p_check() {
            if (p > 1.0) {
                cout << "Pressure is higher than normal" << endl;
            } else if (p < 0.8) {
                cout << "The pressure is very low. Take precaution" << endl;
            } else {
                cout << "Moderate pressure" << endl;
            }
        }

        void h_check() {
            if (h > 70.0) {
                cout << "There's high humidity" << endl;
            } else if (h < 55.0) {
                cout << "Low humidity" << endl;
            } else {
                cout << "Moderate humidity" << endl;
            }
        }
};

int main() {
    string place, sname;
    float t, h, p;
    long sid;

    cout << "Enter the station name: ";
    cin >> sname;
    cout << "Enter the station location: ";
    cin >> place;
    cout << "Enter the station ID: ";
    cin >> sid;
    cout << "Enter the station temperature in celsius: ";
    cin >> t;
    cout << "Enter the station humidity in percentage: ";
    cin >> h;
    cout << "Enter the station pressure in atm: ";
    cin >> p;

    station st(sid, sname, place, t, h, p);

    st.weather();
    st.t_check();
    st.p_check();
    st.h_check();

    return 0;
}
