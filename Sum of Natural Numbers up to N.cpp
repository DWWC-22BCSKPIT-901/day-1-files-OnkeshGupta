#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1; 
    }
    int sum = n * (n + 1) / 2;
    cout << "The sum of natural numbers from 1 to " << n << " is: " << sum << endl;
    return 0;
}