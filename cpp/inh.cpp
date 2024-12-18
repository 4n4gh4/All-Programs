#include <iostream>
using namespace std;
//hierachy inheritance 
class animal{
    private: 
       string name;

    public:
        virtual void makesound(){
            cout<<"Animal makes sound"<<endl;
        }

};

class dog: public animal {
    public:
        void called(){
            cout << "it is calling animal class" << endl;
        }
       
};

class dog2: public animal{
    public:
    void makesound(){
        cout<<"Dog makes sound"<<endl;
        }
};


class cat: public animal{
    public:
    void makesound() override{
        cout<<"Cat makes sound"<<endl;
        }
};

int main(){

    animal a;
    a.makesound();
 
    cat c;
    c.makesound();

    a.makesound();

    dog2 d2;
    d2.makesound();
}