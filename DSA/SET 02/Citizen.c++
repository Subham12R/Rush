#include <iostream>
using namespace std;

struct Citizen{
    int age;
    Citizen* next;
};

Citizen* seniorFront = nullptr;
Citizen* seniorRear = nullptr;
Citizen* normalFront = nullptr;
Citizen* normalRear = nullptr;

void enqueue(Citizen* &front, Citizen* &rear, int age){
    Citizen* newNode = new Citizen();
    newNode->age = age;
    newNode->next = nullptr;

    if(rear == nullptr){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}


void printQueue(Citizen* &front){  // also dequeue func as print works in dequeue manner
    while (front != nullptr){
        cout << front->age << endl;
        Citizen* temp = front;
        front = front->next;
        delete temp;
    }
}

int main() {
    int n, age;

    cout << "Enter number of citizens: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter age of citizen " << i + 1 << ": ";
        cin >> age;

        if (age >= 60)
            enqueue(seniorFront, seniorRear, age);
        else
            enqueue(normalFront, normalRear, age);
    }

    cout << "\n=== Final Vaccination Order ===\n";
    
    // seniors first
    printQueue(seniorFront);

    // normal citizens next
    printQueue(normalFront);

    return 0;
}

