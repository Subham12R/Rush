#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", data);
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    printf("%d popped from stack\n", temp->data);
    free(temp);    
}

void peek(){
    if(top == NULL){
        printf("Stack Empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

void display(){
    if(top == NULL){
        printf("Stack Empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: \n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    int choice, value;
    while(1){
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter value to be pushed: "); scanf("%d", &value); push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}