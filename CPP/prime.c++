#include <iostream>
using namespace std;

void isPrime(int n){
    if(n <=1){
        cout << n << " is not a prime number." << endl;
        return;
    }
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            cout << n << " is not a prime number." << endl;
            return;
        }
    }
    cout << n << " is a prime number." << endl;
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    isPrime(number);

    return 0;
}