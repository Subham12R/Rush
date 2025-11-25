#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* top = nullptr;

void push(int x){
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    cout << "Pushed to stack: " << x << endl;
}

int pop(){
    if(top == nullptr){
        cout << "Stack underflow" << endl;
    }
    int value = top->data;
    Node* temp = top;
    top = top -> next;
    delete temp;
    cout << "Popped from stack" << value << endl;
    return value;
}


int peek(){
    if(top == nullptr){
        cout << "Stack underflow" << endl;
        return -1;
    }
    return top->data;
}

void display(){
    Node* temp = top;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main() {
    push(10);
    push(20);
    push(30);

    display();

    cout << "Top element: " << peek() << endl;

    pop();
    display();

    return 0;
}
