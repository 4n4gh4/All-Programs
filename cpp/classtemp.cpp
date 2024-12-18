#include<iostream>
using namespace std;
template <typename T1, typename T2>

class Pair{

    private:
    T1 first;
    T2 second;

    public:
    Pair<T1,T2>{
        f=0;
        s=0;
    }

    Pair(T1 f, T2 s): first(f), second(s){}

    void display() const{
        cout << "First: "<<first<<"Second: "<<second<<endl;
    }
};

int main(){
    Pair<int,double> p1(10, 3.14);
    p1.display();

    Pair<string,int> p2("Age",25);
    p2.display();
}