#include <iostream>
using namespace std;
   

struct Node {
    int data;
    Node* next;
    Node(int x) {
            data = x;
         next = nullptr;
    }
};
class StackLL {
    private: 
    Node* topNode;
    public:
    StackLL(){
        topNode = nullptr;  
    }

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int poppedValue = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->data;
    }
    bool isEmpty(){
        return topNode == nullptr;
    }

    ~StackLL(){
        while(!isEmpty()){
            pop();
        }
    }
};

int main(){
    StackLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.top() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element is: " << s.top() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    return 0;
}