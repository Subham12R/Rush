#include <iostream>
using namespace std;

class Complex {
    double r, i; // Creating class properties // parameters
public:
    Complex () { r = 0; i = 0; }  // Default constructor -- initialize to 0

    Complex (double real, double imag) { // Parameterized constructor
        r = real;
        i = imag;
    }

    Complex add (Complex c) {
        return Complex (r + c.r, i + c.i);
        // Complex temp; // creating a temporary object
        // temp.r = r + c.r;
        // temp.i = i + c.i;
        // return temp;
    }

    Complex subtract (Complex c) {
        return Complex (r - c.r, i - c.i);
    }

    void display () {
        cout << r << " + " << i << "i" << endl;
    }
    
};

int main () {
    Complex c1 (1, 2);
    Complex c2 (3, 4);
    Complex sum = c1.add (c2);
    Complex difference = c2.subtract (c1);
    cout << "Sum: ";
    sum.display ();
    cout << "Difference: ";
    difference.display ();
    return 0;
}

