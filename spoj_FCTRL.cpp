#include <iostream>

using namespace std;

int trailing(int n) {
    int sum = 0;
    while(n) {
        sum += (n / 5);
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