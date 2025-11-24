#include <iostream>
#include <cmath>
using namespace std;

class Armstrong{
    private:
    int number;
    public:
    Armstrong(int num) : number(num) {} // constructor to initialize number

    bool isArmstrong(){
        int sum = 0, temp, remainder, digits = 0; // initialize variables
        temp = number;

        while(temp != 0){ //counting digits
            digits++;
            temp /= 10;
        }

        temp = number;
        while(temp != 0){ // calculating sum of digits raised to the power of number of digits ex: 153 = 1^3 + 5^3 + 3^3
            remainder = temp % 10;
            sum += pow(remainder, digits);
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

    Armstrong obj(num); // create object of Armstrong class
    if(obj.isArmstrong()){
        cout << num << " is an Armstrong number." << endl;
    }else{
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}