#include <iostream>
using namespace std;
int main() {
    int n, count = 0;
    cout << "Enter a positive integer: ";
    cin >> n;
    while (n != 0) {
        n /= 10;
        count++;
    }
    cout << "The total number of digits is: " << count << endl;
    return 0;
}