#include <iostream>
using namespace std;

class Menu {
    public: 
    void displayOptions() {
        cout << "Menu Options:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Swap" << endl;
        cout << "3. Exit" << endl;
    }

    void add(){
        cout << "Add option selected." << endl;
        int a, b;
        cout << "Enter two numbers to add: ";
        cin >> a >> b;
        cout << "Sum: " << a + b << endl;
    }

    void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
        cout << "After swapping: " << a << " " << b << endl;
    }

    void swapOption(){
        cout << "Swap option selected." << endl;
        int a, b;
        cout << "Enter two numbers to swap: ";
        cin >> a >> b;
        swap(a, b);
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
            menu.add();
            break;
        case 2:
            menu.swapOption();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}