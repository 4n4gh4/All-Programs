#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Student{

    private:

    string name;
    int age;
    double grade;
    
    public:

    std::vector<string, double> myv;

    Student(){
        name = "blank";
        age = 0;
        grade = 0.0;
    }

    Student(string x, int y, double z){
       name = x;
       age = y;
       grade = z;

    }

    void copy(Student){

        

    }


    void print(){
        cout<<"Student name: "<<name<<endl<<"Student age: "<<age<<endl<<"Student grade: "<<grade;
    }

};

int main(){
    
    list<Student> myl = {

        Student("ABP", 2, 10.5),
        Student("PMS", 34, 15.9),
        Student("SKN", 45, 20),
        Student("VV", 52, 11.6)
    };


    


    

    return 0;
}