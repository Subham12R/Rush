#include <iostream>
using namespace std;

class Solution{
    int n;
    public:
    Solution(int N) : n(N) {}

    int fib(int n){
        if(n <= 0) return 0;
        if(n == 1) return 1;
        return fib(n-1) + fib(n-2);
    }

    void printFib(int n){
        int a = 0, b = 1;
        if(n <= 0) {
            return;
        }
        cout << a << " ";
        if(n == 1){
            return;
        }
        cout << b << " ";

        for (int i = 3; i <= n ; i++){
            int c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
};


int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    Solution obj(number);
    cout << "Fibonacci of " << number << " is: " << obj.fib(number) << endl;

    Solution obj2(number);
    cout << "Fibonacci series up to " << number << ": ";
    obj2.printFib(number);
    return 0;
}



