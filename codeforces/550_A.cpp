#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    auto first_ab = s.find("AB", 0);
    auto first_ba = s.find("BA", 0);

    if (first_ab == string::npos || first_ba == string::npos) {
        cout << "NO" << endl;
        return 0;
    }
    if (first_ab != first_ba && abs(static_cast<int>(first_ab - first_ba)) > 1) {
        cout << "YES" << endl;
        return 0;
    }

    // got it wrong initially because I had auto second_ab = s.find("AB", first_ab + 2); initally
    // thought we actually want to find non-overlapping so we want to to start looking for ab after ba
    // and start looking for the 2nd ba after the first ab. Finding the second ab after the first ab
    // doesn't matter.
    // Example: ABAB will return a "YES" in this scenario even though it is invalid
    auto second_ab = s.find("AB", first_ba + 2);
    auto second_ba = s.find("BA", first_ab + 2);
    if (second_ab != string::npos || second_ba != string::npos) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
