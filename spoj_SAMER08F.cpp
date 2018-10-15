#include <iostream>

using namespace std;

int main() {
    int dp[101];
    dp[1] = 1;
    dp[2] = 5;
    for (int i=3; i<=100; i++) {

        // originally I did dp[i] = dp[i-1]*4 + 1, but that overcounted by too much
        // because the sub-squares would count common sub-squares. For example,
        // n=3, the top left and top right square solutions would both count the middle
        // square.

        // correct way to do this problem is consider all the new squares that are
        // added with each iteration. We add a top row and a row to the right and
        // loop through all the cases, where each case is the size of the square.
        int newSquares = 0;
        for (int j=1; j<=i; j++) {
            newSquares += (i-j+1)*2 - 1;
        }

        dp[i] = dp[i-1] + newSquares;
    }

    int n;
    while(cin >> n && n != 0) {
        cout << dp[n] << endl;
    }
    return 0;
}
