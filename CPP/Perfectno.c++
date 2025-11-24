#include <iostream>
using namespace std;

class Solution {
    int num;
    public:
    Solution(int N) : num(N) {}

    bool isPerfect(){
        int sum = 0;
        for(int i = 1; i <= num / 2; i++){ // finding divisors and summing them ex: 6 = 1 + 2 + 3
            if(num % i == 0){
                sum += i; // add divisor to sum
            }
        }
        return sum == num;
    }

};

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    Solution obj(number);
    if(obj.isPerfect()){
        cout << number << " is a Perfect number." << endl;
    }else{
        cout << number << " is not a Perfect number." << endl;
    }
    return 0;
}