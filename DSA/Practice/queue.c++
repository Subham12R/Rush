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

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int x){
    Node* q = new Node(x);

    if(rear == nullptr){
        front = rear = q;
    }else{
        rear->next = q;
        rear = q;
    }

    cout << x << " senqueued." << endl; 
}

int dequeue(){
    if(front == nullptr){
        cout << "Queue underflow!";
        return -1;
    }

    Node* temp = front;
    int value = temp->data;

    front = front->next;

    if(front == nullptr)rear = nullptr;

    delete temp;

     cout << value << " dequeued." << endl;
    return value;
}

int peek(){
    if(front == nullptr){
        cout << "Queue empty!";
        return -1;
    }
    return front->data;
}

void display(){
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }


    Node* temp = front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    cout << "Front element: " << peek() << endl;

    dequeue();
    display();

    return 0;
}