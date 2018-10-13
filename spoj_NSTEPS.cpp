#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int x,y;
    while(t--) {
        cin >> x >> y;
        if (x != y && x - y != 2) {
            cout << "No Number" << endl;
            continue;
        }

        if (y % 2 == 0) {
            cout << x + y << endl;
        } else {
            cout << x + y - 1 << endl;
        }
    }
    return 0;
}
