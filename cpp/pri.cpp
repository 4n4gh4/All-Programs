#include<iostream>
#include<queue>

using namespace std;

int main(){

    std::priority_queue<int> pq;

    pq.push(40);
    pq.push(100);
    pq.push(2);
    pq.push(50);
    pq.push(44);
    pq.push(73);

    int s= pq.size();

    for(int i=0;i<s;i++){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}