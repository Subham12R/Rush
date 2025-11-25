#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
    printf("Inserted: %d\n", value);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    // Move front pointer forward
    front++;

    // Reset queue when it becomes empty
    if (front > rear)
        front = rear = -1;
}

// Peek/Front operation
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
