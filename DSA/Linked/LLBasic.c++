#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void createLL(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data;
        if(temp -> next != NULL){
            cout << " -> ";
        }else{
            cout << " -> NULL";
        }
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    createLL(head, tail, 10);
    createLL(head, tail, 20);
    createLL(head, tail, 30);
    printLL(head);
    return 0;
}