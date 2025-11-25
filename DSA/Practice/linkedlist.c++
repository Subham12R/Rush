#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int x){
        data = x;
        next = nullptr;
    }
};

Node* head = nullptr;

Node* createNode(int x){
    Node* newNode = new Node(x);
    return newNode;
}

void insertHead(int x){
    Node* newNode = createNode(x);
    newNode->next = head;
    head = newNode;
}

void insertTail(int x){
    Node* newNode = createNode(x);

    if(head == nullptr){
        head = newNode;
        return;
    };

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertPos(int x, int pos){
    if(pos == 1){
        insertHead(x);
        return;
    }

    Node* newNode = createNode(x);
    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp->next != nullptr; i++){
        temp = temp->next;
    }
    newNode->next=temp->next;
    temp->next = newNode;
}


void deleteHead(){
    if(head == nullptr){
        cout << "List Empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(){
    if(head == nullptr){
        cout << "List Empty!" << endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

}

void deletePos(int pos) {
    if(pos == 1){
        deleteHead();
        return;
    }

    Node* temp = head;


    for(int i = 1; i < pos - 1 && temp->next != nullptr; i++)temp = temp->next;

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}

void display(){
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> " ;
        temp = temp->next;
    }
    cout<< "NULL" << endl;
}

void search(int x){
    Node* temp = head;
    bool found = false;
    int pos = 1;
    while(temp != nullptr){
        if(temp->data == x){
            cout << "Found at: " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if(!found)cout<<"Not found in list";
}


int main() {
    insertHead(10);
    insertTail(20);
    insertTail(30);
    insertPos(15, 2);

    display();

    search(20);

    deleteHead();
    deleteTail();
    deletePos(2);

    display();

    return 0;
}