#include <iostream>
using namespace std;

class ArrStack{
    private:
        static const int MAX = 1000;
        int arr[MAX];
        int topIndex;
    public:
        ArrStack() {
            topIndex = -1;
        }

        void push(int x){
            if(topIndex >= MAX - 1){
                cout << "Stack Overflow" << endl;
                return;
            }
        arr[++topIndex] = x;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[topIndex--];

        }

        int top(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[topIndex];
        }

        bool isEmpty(){
            return topIndex == -1;
        }
        int size(){
            return topIndex + 1;
        }
    };


    int main(){
        ArrStack stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        cout << "Top element is: " << stack.top() << endl;
        cout << "Stack size is: " << stack.size() << endl;

        stack.pop();
        cout << "Top element is: " << stack.top() << endl;

        return 0;
    }