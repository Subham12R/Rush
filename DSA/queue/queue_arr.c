#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() { return front == -1 || front > rear; }
int isFull() { return rear == SIZE - 1; }

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
    if (front > rear) front = rear = -1;
}

// Display
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();

    dequeue();
    display();
    return 0;
}
