#include <iostream>
#include <cstring>
using namespace std;

class Solution{
    private:


    public:

    int evaluate(int a, int b){
        return a + b;
    }
    int evaluate(double a, double b){
        return a * b;
    }

    string evaluate(string a, string b){
        return a + b;
    }


};


int main() {
    Solution obj;

    cout << "Sum of integers: " << obj.evaluate(10, 20) << endl;
    cout << "Product of doubles: " << obj.evaluate(5.5, 4.5) << endl;
    cout << "Concatenation of strings: " << obj.evaluate("Hello, ", "World!") << endl;

    return 0;
}