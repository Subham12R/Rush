#include <iostream>
#include <cmath>
using namespace std;

class Menu {
public:
    void displayOptions() {
        cout << "Menu Options:" << endl;
        cout << "1. Strong Number" << endl;
        cout << "2. Armstrong Number" << endl;
        cout << "3. Exit" << endl;
    }
    
    int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
        return fact;
    }

    void checkStrongNumber() {
        cout << "Strong Number option selected." << endl;
        int num, sum = 0, temp, digit;
        cout << "Enter a number: ";
        cin >> num;
        temp = num;
        while (temp != 0) {
            digit = temp % 10;
            sum += factorial(digit);
            temp /= 10;
        }
        if (sum == num)
            cout << num << " is a Strong Number." << endl;
        else
            cout << num << " is not a Strong Number." << endl;
    }


    void checkArmstrongNumber() {
        cout << "Armstrong Number option selected." << endl;
        int num, sum = 0, temp, digit, digits = 0;
        cout << "Enter a number: ";
        cin >> num;
        temp = num;
        
        // Count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        
        temp = num;
        while (temp != 0) {
            digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        if (sum == num)
            cout << num << " is an Armstrong Number." << endl;
        else
            cout << num << " is not an Armstrong Number." << endl;
    }
};


// A strong number is a positive integer where the sum of the factorials of its individual digits equals the number itself. 
// For example, 145 is a strong number because \(1!+4!+5!=1+24+120=145\)

// An Armstrong number, also known as a narcissistic number, is a number that equals the sum of its own digits, 
// each raised to the power of the total number of digits in the number. For example, 
// \(153\) is an Armstrong number because it has three digits, and the sum of its digits raised to the third power is 
// \(1^{3}+5^{3}+3^{3}=1+125+27=153\). 

int main() {
    Menu menu;
    menu.displayOptions();
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice) {
        case 1:
            menu.checkStrongNumber();
            break;
        case 2:
            menu.checkArmstrongNumber();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}