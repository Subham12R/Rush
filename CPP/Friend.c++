#include <iostream>
using namespace std;


class Solution{
    private:
    string name;
    int age;
    public:
    Solution(string Name, int Age) : name(Name), age(Age) {}
    friend void displayCandidateInfo(const Solution& candidate);
    
};

    void displayCandidateInfo(const Solution& candidate) {
    cout << "Displaying Candidate Info - Name: " << candidate.name << ", Age: " << candidate.age << endl;
    }


int main() {
    Solution candidate1("Alice", 30);
    displayCandidateInfo(candidate1);

    Solution candidate2("Bob", 25);
    displayCandidateInfo(candidate2);

    return 0;
}