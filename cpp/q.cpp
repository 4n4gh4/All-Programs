#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    queue<int> myq;
    
    myq.push(10);
    myq.push(20);
    myq.push(10);
    myq.push(20);
    
    cout<<"the q size is: "<<myq.size()<<endl;
    cout<<"in front: "<<myq.front()<<endl;
    cout<<"in back: "<<myq.back()<<endl;
    
    return 0;
}