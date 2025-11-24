#include <iostream>
#include <cmath>
using namespace std;

class Menu {
public:
    void displayOptions() {
        cout << "Menu Options:" << endl;
        cout << "1. Perfect Number" << endl;
        cout << "2. Armstrong Number" << endl;
        cout << "3. Exit" << endl;
    }
    
        
    /**
     * This function checks if a given number is a perfect number.
     * A perfect number is a positive integer that is equal to the sum of its proper positive divisors, excluding the number itself.
     * For example, 6 is a perfect number because 1, 2, and 3 are its proper positive divisors, and the sum of these divisors is 6.
     */
    void checkPerfect() {
        cout << "Perfect Number option selected." << endl;
        int num, sum = 0;
        cout << "Enter a number: ";
        cin >> num;

        for (int i = 1; i <= num / 2; i++)
        {
            if(num % i == 0) {
                sum += i;
            }
        }
        if (sum == num)
            cout << num << " is a Perfect Number." << endl;
        else
            cout << num << " is not a Perfect Number." << endl;
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




int main() {
    Menu menu;
    menu.displayOptions();
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice) {
        case 1:
            menu.checkPerfect();
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