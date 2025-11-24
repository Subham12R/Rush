#include <iostream>
using namespace std;

class Car {
    public: 
    string brand;
    string model;

    Car(string Brand, string Model) : brand(Brand), model(Model) {
        cout << "Car Brand: " << brand << ", Model: " << model << endl;
    }
};

class Vehicle : public Car {
    public:
    int year;

    Vehicle(string Brand, string Model, int Year) : Car(Brand, Model), year(Year) {
        cout << "Vehicle Year: " << year << endl;
    }
};

class FuelType : public Vehicle {
    public:
    string fuel;

    FuelType(string Brand, string Model, int Year, string Fuel) : Vehicle(Brand, Model, Year), fuel(Fuel) {
        cout << "Fuel Type: " << fuel << endl;
    }
};


int main() {
    FuelType myCar("Toyota", "Corolla", 2020, "Gasoline");
    return 0;
}