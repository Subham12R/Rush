#include <iostream>
using namespace std;

class Employee {
    private:
    float salary;
    float allowance;

    public:

    void getData() {
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter allowance: ";
        cin >> allowance;
    }   
    
    float totalCompensation() {
        return salary + allowance;
    }

};

int main() {
    Employee emp[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for Employee " << i+1 << ":" << endl;
        emp[i].getData();
    }

  cout << "\n--- Total Salaries of Employees ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Employee " << i+1 << ": " 
             << emp[i].totalCompensation() << endl;
    }
    
    return 0;
}