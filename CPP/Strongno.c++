#include <iostream>
#include <cmath>
using namespace std;

class Strong{
    private:
    int number;
    public:
    Strong(int num) : number(num) {} // constructor to initialize number

    int factorial(int n){
        if(n <= 1) return 1;
        return n * factorial(n - 1); //recursive factorial function
    }
    bool isStrong(){
        int sum = 0, temp, remainder, digits = 0; // initialize variables
        temp = number;

        while(temp != 0){ //counting digits
            digits++;
            temp /= 10;
        }

        temp = number;
        while(temp != 0){  // calculating sum of factorials of digits ex: 145 = 1! + 4! + 5!
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

    Strong obj(num); // create object of Strong class
    if(obj.isStrong()){
        cout << num << " is a Strong number." << endl;
    }else{
        cout << num << " is not a Strong number." << endl;
    }
    return 0;
}