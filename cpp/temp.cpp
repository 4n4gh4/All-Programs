#include<iostream>
using namespace std;
template <typename p1, typename p2, typename p3>
float add(p1 a,p2 b,p3 c){
    return a+b+c;
}

int main(){

    float a, b, c;

    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter c` ";
    cin>>c;

    cout<<"The sum is: "<<add(a,b,c)<<endl;
    cout<<"Sum of 5.6 and 5 and 8.3"<<add(5.6,5,8.3)<<endl;
    cout<<"Sum of 1 and 2 and 78.9: "<<add(1,2,78.9)<<endl;
    return 0;

}