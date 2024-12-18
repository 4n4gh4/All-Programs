#include<iostream>
using namespace std;

template <typename X, typename Y>
X add(X a, Y b){
    return a+b;
}

int main(){

    int a;
    float b;

    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;

    cout<<"Sum is: "<<add(a,b);
    
}