#include<iostream>
#include<string>
using namespace std;

class Student{

    private:

    int roll;
    string name;
    int age;
    
    public:

    Student(){
        name = "taravu";
        roll = 0;
        age = 5;

    }

    Student(int a, int b, string c){
        name = c;
        roll = a;
        age = b;
    }

    void display(){
        cout << "The student name: " << name <<endl;
        cout <<"Student roll: " << roll << endl;
        cout << "Student age: " << age <<endl;
    }

    void YOB(int x){

        cout<< "Birth year is: " << 2024 - x;

    }

    ~Student(){
        cout <<"Object released!" <<endl;
    }
};

int main(){

    int roll, age;
    string name;

    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter roll number: ";
    cin>>roll;
    cout<<"Enter age: ";
    cin>>age;

    Student akhil(56,14,"bobby"), akarsh;

    akhil.display();

    cout<<endl;

    akarsh.YOB(age);

    cout<<endl;


   Student saurabh(roll, age, name);

   saurabh.display();



    return 0;
}