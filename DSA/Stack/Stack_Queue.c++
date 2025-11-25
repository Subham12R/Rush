#include <iostream>
#include <queue>
using namespace std;

class StackQueue {
    private: 
    queue <int> q1, q2;
    public: 
    void push(int x){
        q1.push(x);
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int pop(){
        if(q2.empty()){
            return -1;
        }
        int val = q2.front();
        q2.pop();
        return val;
    }

    int top(){
        if(q2.empty()){
            return -1;
        }
        return q2.front();
    }

    bool isEmpty(){
        return q2.empty();
    }
};

int main(){
    StackQueue sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    cout << "Top element: " << sq.top() << endl;
    cout << "Popped element: " << sq.pop() << endl;
    cout << "Is empty: " << sq.isEmpty() << endl;
    return 0;
}