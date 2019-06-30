#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main() {
    // n is start
    // m is target
    int n, m, w(0);
    cin >> n >> m;

    if (n == m ) {
        cout << "0" <<endl;
        return 0;
    }
    if (n > m) {
        cout << n - m << endl;
        return 0;
    }

    // if we start with the target rather than n
    // we are gauranteed to get the shortest path by
    // only dividing when m is even.
    // Why?
    // Suppose there was a faster way. Suppose you want to add 1 instead.
    // Well you will need to add 1 twice, before you can divide by 2 again.
    // And, that goes in the opposite direction so its an additional 2 steps.
    while (n < m) {
        if (m % 2) m /= 2, w++;
        else m++, w++;
    }
    if (n != m) {
        w += (n - m);
    }

    cout << w << endl;
    return 0;
}
