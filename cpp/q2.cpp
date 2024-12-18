#include<iostream>
#include<queue>

using namespace std;

class Student{

    private:
    string name;
    int roll;

    public:
    
    Student(){
        name = "blank";
        roll = 0;
    }

    Student(string a, int b){
        name = a;
        roll = b;

    }
    
    void display(){
        cout<<name<<" "<<roll<<endl;
    }


};

int main(){
    
    queue<Student> stu;

    Student s1("PMS", 34), s2("ABP",2), s3("SKN",45), s4("VV",52);

    stu.push(s1);
    stu.push(s2);
    stu.push(s3);
    stu.push(s4);
    
    cout<<"total students: "<<stu.size()<<endl;
    cout<<"1st to enter: ";
    stu.front().display();
    cout<<"last: ";
    stu.back().display();
    
    return 0;
}