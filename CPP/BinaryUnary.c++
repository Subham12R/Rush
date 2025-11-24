#include <iostream>
using namespace std;

class Number {
    int value;

public:
    // Parameterized constructor
    Number(int v = 0 ) { value = v; }

    void operator + (Number n) {
        cout << "Addition: " << (value + n.value) << endl;
    }

    void operator ++ () {
        value++;
        cout << "After Increment: " << value << endl;
    }
};

int main() {
    Number num1(5);
    Number num2(10);

    num1 + num2; // Using overloaded + operator

    ++num1; // Using overloaded ++ operator

    return 0;
}

