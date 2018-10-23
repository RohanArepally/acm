#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    while (cin >> a >> b >> c && !(a==0 && b==0 && c==0)) {
        if (c-b == b-a) {
            int ap = b-a;
            cout << "AP " << ap + c << endl;
        } else {
            int gp = b/a;
            cout << "GP " << gp * c << endl;
        }
    }
    return 0;
}
