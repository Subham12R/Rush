#include <iostream>
using namespace std;

class Car {
private:
    int id;
    string brand;
    float price;

public:
    // Function to accept data
    void getData() {
        cout << "Enter Car ID: ";
        cin >> id;

        cout << "Enter Car Brand: ";
        cin >> brand;

        cout << "Enter Price per Day: ";
        cin >> price;
    }

    // Function to display one car
    void display() {
        cout << "ID: " << id 
             << ", Brand: " << brand 
             << ", Price: " << price << endl;
    }
};

int main() {
    Car c[3];   // Array of 3 car objects

    cout << "--- Enter details of 3 Cars ---\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nCar " << i+1 << ":\n";
        c[i].getData();
    }

    cout << "\n--- Car Details ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "Car " << i+1 << ": ";
        c[i].display();
    }

    return 0;
}
