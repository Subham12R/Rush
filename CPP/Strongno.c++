#include <iostream>
#include <cmath>
using namespace std;

class Strong{
    private:
    int number;
    public:
    Strong(int num) : number(num) {}

    int factorial(int n){
        if(n <= 1) return 1;
        return n * factorial(n - 1);
    }
    bool isStrong(){
        int sum = 0, temp, remainder, digits = 0;
        temp = number;

        while(temp != 0){
            digits++;
            temp /= 10;
        }

        temp = number;
        while(temp != 0){
            remainder = temp % 10;
            sum += factorial(remainder);
            temp /= 10;
        }
        if(sum == number){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    Strong obj(num);
    if(obj.isStrong()){
        cout << num << " is a Strong number." << endl;
    }else{
        cout << num << " is not a Strong number." << endl;
    }
    return 0;
}