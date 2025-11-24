#include <iostream>
using namespace std;


class Solution{
    private: 
    int a, b;

    public:
    Solution(int A, int B) : a(A), b(B) {}

    inline int add(){
        return a + b;
    }
    
};



int main() {
    Solution obj(10, 20);
    cout << "The sum is: " << obj.add() << endl;
    return 0;
}