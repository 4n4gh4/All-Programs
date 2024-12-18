#include<iostream>
using namespace std;

template<typename x, typename y, typename z>

class three{

    private:
    x a;
    y b;
    z c;

    public:

    three(){
        a=0;
        b=0;
        c=0;
    }

    three(x aa, y bb, z cc){
        a = aa;
        b = bb;
        c = cc;
    }

    void display() const{
        cout<<endl<<endl<<a<<" "<<b<<" "<<c;
    }

};

int main(){

    three<int, int, int> obj1;
    obj1.display();

    three<string, int, char> o2("meow",1,'o');
    o2.display();

}