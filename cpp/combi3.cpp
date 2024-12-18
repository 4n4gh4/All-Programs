#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>  // For std::sort

using namespace std;

// Student class definition
class Student {
public:
    string name;
    int age;
    double grade;

    Student(string n, int a, double g) : name(n), age(a), grade(g) {}
};

// Function to copy names and grades from list to vector
vector<pair<string, double>> copyToVector(list<Student>& students) {
    vector<pair<string, double>> result;

    for (auto& student : students) {
        result.push_back(make_pair(student.name, student.grade));
    }

    return result;
}

// Function to sort the vector by grade in descending order
void sortStudentsByGrade(vector<pair<string, double>>& studentVector) {
    sort(studentVector.begin(), studentVector.end(),
        [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;  // Sort by grade in descending order
        });
}

// Function to print sorted students
void printSortedStudents(const vector<pair<string, double>>& studentVector) {
    cout << "Sorted students by grade:" << endl;
    for (const auto& student : studentVector) {
        cout << student.first << " - Grade: " << student.second << endl;
    }
}

int main() {
    // Create a list of Student objects
    list<Student> studentList = {
        Student("Alice", 20, 88.5),
        Student("Bob", 22, 95.0),
        Student("Charlie", 19, 72.4),
        Student("Diana", 21, 89.2)
    };

    // Copy student names and grades into a vector
    vector<pair<string, double>> studentVector = copyToVector(studentList);

    // Sort students by grade in descending order
    sortStudentsByGrade(studentVector);

    // Print sorted students
    printSortedStudents(studentVector);

    return 0;
}
