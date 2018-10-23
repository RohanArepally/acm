#include <iostream>

using namespace std;

int reverse(int n) {
    int r = 0;
    while(n) {
        r *= 10;
        r += (n % 10);
        n /= 10;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = reverse(a) + reverse(b);
        cout << reverse(sum) << endl;
    }
}