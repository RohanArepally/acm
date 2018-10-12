#include <iostream>

using namespace std;

int trailing(int n) {
    int sum = 0;
    while(n) {
        sum += (n / 5);
        // need to divide because you need to count cases where numbercs can have multiple
        // factors of 5. 25 is 5^2 and 125 is 5^3.
        n /= 5;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        cout << trailing(n) << endl;
    }
}