#include <iostream>
using namespace std;

class Employee {
public:
    virtual void evaluate() = 0; // Pure virtual function
};

class Manager: public Employee {
    int teams;
public:
    Manager(int t) : teams(t) {}
    void evaluate() override {
        cout << "Manager has evaluated: " << teams << " teams." << endl;
    }
};

class Developer: public Employee {
    int projects;
public:
    Developer(int p) : projects(p) {}
    void evaluate() override {
        cout << "Developer has evaluated: " << projects << " projects." << endl;
    }
};



int main() {
    Employee* emp1 = new Manager(5);
    Employee* emp2 = new Developer(3);

    emp1->evaluate();
    emp2->evaluate();

    delete emp1;
    delete emp2;

    return 0;
}

