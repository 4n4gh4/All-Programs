#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Student class


class Student {
private:
    string name;
    int id;
    string major;

public:
    //default constructor 
    Student(){
        name = "blank";
        id=0;
        major="blank";
    }

    //parametrised constructor
    Student(string a, int b, string c) {
        name = a;
        id = b;
        major = c;
    }

    void displayDetails() const{
        cout << "Name: " << name <<endl;
        cout<<"ID: " << id <<endl;
        cout<<"Major: " << major << endl<<endl;
    }

    int getId() const {
        return id;
    }
};


int main() {
    int choice;
    string a, c;
    int b;

    queue<int> myq;
    map<int, Student> det;

    do {
        cout << "\n--- Menu ---\n";    
        cout << "1. Add a Student to the queue and map\n";
        cout << "2. Display the details of the first student in the queue\n";
        cout << "3. Remove the first student from the queue after processing\n";
        cout << "4. Display all stored Student IDs and details from the map\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1) {             //1. Add a Student to the queue and map

            cout << "Enter student name: ";
            cin >> a;        
            cout << "Enter student ID: ";
            cin >> b;        
            cout << "Enter student major: ";
            cin >> c;

            Student student(a,b,c);
            det[b] = student;
            myq.push(b);
        }
            
            
        else if(choice==2){                 //    2. Display the details of the first student in the queue

            if (!myq.empty()) {
                int fid = myq.front();
                det[fid].displayDetails();
            }
            
            else {
                cout << "Queue is empty.\n";
            }
            
            }
            
        else if(choice == 3){           //    3. Remove the first student from the queue after processing


            if (!myq.empty()) {
                myq.pop();
                cout << "First student removed from the queue.\n";
            } else {
                cout << "Queue is empty.\n";
            }
            }

        else if (choice == 4)
        
        {  
            if (det.empty()) { 
                cout << "No students stored in the map.\n";
            }
            
            else {
                cout << "Stored Student Details:\n";
        
                for (auto it = det.begin(); it != det.end(); ++it) {
                cout << "ID: " << it->first << ", ";
                it->second.displayDetails();
                }
            }
        }



        else if(choice==5){               //5. Exit
            cout << "Code exiting\n";
        
        }
        
        else{
            cout << "Invalid choice. Please try again.\n";
        }


    } while (choice != 5);

    return 0;
}
