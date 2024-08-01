#include<iostream>
#include<string>
using namespace std;

class student {
private:
    string roll;
    string name;
    string dob;
    string gender;
    string addr;
    float sgpa[8];
    float cgpa;
    
      //these are the private keys in the class student

public:
    student(string r, string n, string d, string g, string a, float s[8]) {
        roll = r;
        name = n;
        dob = d;
        gender = g;
        addr = a;
        for (int i = 0; i < 8; i++) {
            sgpa[i] = s[i];
        }
        ccgpa();
    }

    void ccgpa() {
        float sum = 0.0;
        for (int i = 0; i < 8; i++) {
            sum += sgpa[i];
        }
        cgpa = sum / 8;
    } //calculates cgpa from sgpa

    void pcgpa() {
        cout << "Current CGPA of student is " << cgpa << endl;
    } //publishes student cgpa

    void psgpa() {
        for (int i = 0; i < 8; i++) {
            cout << "Current SGPA for semester " << (i + 1) << " is: " << sgpa[i] << endl;
        }
    } //publishes student sgpa

    void dstudent() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << addr << endl;
        psgpa();
        pcgpa();
    }//displays student details

    void uname(string nname) {
        name = nname;
    }//function to update name

    void uaddr(string naddr) {
        addr = naddr;
    }//function to update address
}; 

int main() {
    float sgpa[8];
    string name, roll, dob, gender, addr;

    cout << "Enter roll number of student: ";
    cin >> roll;
    cout << "Enter name of the student: ";
    cin >> name;
    cout << "Enter date of birth of student: ";
    cin >> dob;
    cout << "Enter gender of student: ";
    cin >> gender;
    cout << "Enter address of student: ";
    cin >> addr;
    //takes input for each field

    for (int i = 0; i < 8; i++) {
        cout << "Enter SGPA for semester " << i + 1 << ": ";
        cin >> sgpa[i];
    }//takes sgpa input for each sem

    student s(roll, name, dob, gender, addr, sgpa);

    s.dstudent();
    s.uname("Anagha");
    s.uaddr("Trivandrum");
    cout << "\nUpdated details:" << endl;
    s.dstudent();

    return 0;
}
