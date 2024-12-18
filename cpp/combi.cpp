#include<iostream>
#include<map>
#include<deque>

using namespace std;

class Recent{

    private:
    map<int, std::string> item;
    std::deque<int> order;

    public:
    Recent(){
        item = {{0,"blank"}};
        order.push_front(0);

    }

    Recent(int x, string y){
        item.insert({x,y});
        order.push_back(x);
    }

    void additem(int x, string y){
        item[x] = y;
        order.push_front(x);
        
        while(item.size()>10){
            int a = order.back();
            item.erase(a);
            order.pop_back();
        }
    }

    string access(int x){
    string res;
    auto it = item.find(x);

    if (it != item.end()) {
        int y = it->first;

        // Manually find and erase the element in the deque
        for (auto deque_it = order.begin(); deque_it != order.end(); ++deque_it) {
            if (*deque_it == y) {
                order.erase(deque_it);
                break;
            }
        }

        order.push_front(y);

        res = it->second;
    } else {
        res = "Item not found";
    }

    return res;
}


    void print(){
        
        for (auto it = item.begin();it!=item.end();++it){
            cout<<"["<<it->first<<"]: "<<it->second<<endl;
        }
    }



};

int main(){
    
    Recent a,b,c;
    a.additem(1,"apple");
    a.print();


    return 0;
}