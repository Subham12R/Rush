#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    int m1, m2, m3;
public:
    Student(string n, int r, int m1, int m2, int m3) : name(n), roll(r) , m1(m1), m2(m2), m3(m3) {}
    void grade() {
        int totalMarks = m1 + m2 + m3;
        if (totalMarks >= 80)cout << "Grade: A" << endl;
        else if (totalMarks >= 70 && totalMarks <= 79)cout << "Grade: B" << endl;
        else if (totalMarks >= 60 && totalMarks <= 69)cout << "Grade: C" << endl;
        else if (totalMarks >= 50 && totalMarks <= 59)cout << "Grade: C" << endl;
        else cout << "Fail" << endl;
    }
    void display() {
        cout << "Student Details For" << endl;
        cout << "Name: " << name << endl;
        cout << "TotalMarks: " << m1 + m2 + m3 << endl;
        grade();
    }


};

int main(){
    Student stu1("Alice", 101, 85, 78, 92);
    Student stu2("Bob", 102, 75, 68, 80);
    Student stu3("Bob", 102, 75, 68, 80);
   
    stu1.display();
    stu2.display();
    stu3.display();

    return 0;
}