#include <iostream>
#include <string>
using namespace std;

class Book {
    string name;
    double length; // in cm (or any unit)
    double breadth;
    double height;

public:
    // Parameterized constructor: set name and dimensions
    Book(const string &n, double l, double b, double h)
        : name(n), length(l), breadth(b), height(h) {}

    // Calculate volume (length * breadth * height)
    double volume() const {
        return length * breadth * height;
    }

    void display() const {
        cout << "Book: " << name << " | Dimensions: "
             << length << " x " << breadth << " x " << height
             << " | Volume: " << volume() << endl;
    }
};

int main() {
    // Create two books using the parameterized constructor
    Book b1("C++ Primer", 24.0, 18.0, 3.5); // dimensions in cm
    Book b2("Algorithms", 23.5, 16.5, 4.0);

    cout << "Volumes of two books:\n";
    b1.display();
    b2.display();

    cout << "Total volume: " << (b1.volume() + b2.volume()) << endl;
    return 0;
}