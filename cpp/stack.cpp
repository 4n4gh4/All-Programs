#include<iostream>
#include<stack>

using namespace std;

int main(){
    
stack<int> superstack;

superstack.push(1);
superstack.push(2);
superstack.push(4);

if(superstack.empty()){
    cout<<"Stack is empty\n";
}

else{
    cout<<"Stack is not empty";
}

cout<<"The top element is: "<<superstack.top()<<endl;

cout<<"Elements of the stack are: "<<endl;
while(!superstack.empty()){
    cout<<superstack.top()<<" ";
    superstack.pop();
}

return 0;

}