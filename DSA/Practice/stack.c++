#include <iostream>
using namespace std;

typedef struct Stack {
    static const int MAX = 10;
    int arr[MAX];
    int top;
}Stack;


Stack* createStack(){
    Stack* newStack = new Stack;
    newStack->top = -1;
    
    return newStack;
}


void push(Stack* s, int x){
    if(s->top >= Stack::MAX - 1){
        cout << "Stack overflow"<< endl;
    }else{
        s->arr[++s->top] = x;
        cout << "Pushed " << x << "to stack" << endl;
    }
}

int pop(Stack *s){
    if(s->top == -1){
        cout << "stack underflow" << endl;
        return -1;
    }
    else{
        int val = s->arr[--s->top];
        cout << "Popped " << val << "from stack"<<endl;
        return val;
    }
}

int peek(Stack *s){
    if(s->top == -1){
        cout << "stack underflow" << endl;
        return -1;
    }
    else{
        return s->arr[s->top];
    }
}

void display(Stack *s){
    if (s->top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        for(int i = s->top; i >= 0; i--){
            cout << s->arr[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    Stack *s = createStack();

     push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);

        cout << "Top element is: " << peek(s) << endl;

    pop(s);
    display(s);

    return 0;
}