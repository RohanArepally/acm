/*
 *
4 2
ABBA
ABBB
BAAA
BABB
AB
BB
0 0
*
*
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s

int main() {

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;

        char big[a][a];
        char small[b][b];

        for (int row=0; row<a; row++) {
            for (int col=0; col<a; col++) {
                cin >> big[row][col];
            }
        }

        for (int row=0; row<b; row++) {
            for (int col=0; col<b; col++) {
                cin >> small[row][col];
            }
        }

        int zero = 0;
        int ninety = 0;
        int one_eighty = 0;
        int two_seventy = 0;
        for (int i=0; i<a-b+1; i++) {
            for (int j=0; j<a-b+1; j++) {


                bool is_zero = true;
                bool is_ninety = true;
                bool is_one_eighty = true;
                bool is_two_seventy = true;

                for (int k=0; k<b; k++) {
                    for (int l=0; l<b; l++) {
                        char big_value = big[i+k][j+l];

                        if (big_value != small[k][l]) {
                            is_zero = false;
                        }
                        if (big_value != small[b - 1 - l][k]) {
                            is_ninety = false;
                        }
                        if (big_value != small[b - 1 - k][b - 1 - l]) {
                            is_one_eighty = false;
                        }
                        if (big_value != small[l][b - 1 - k]) {
                            is_two_seventy = false;
                        }
                    }
                }

                if (is_zero) zero++;
                if (is_ninety) ninety++;
                if (is_one_eighty) one_eighty++;
                if (is_two_seventy) two_seventy++;
            }
        }

        cout << zero << " " << ninety << " "  << one_eighty << " " << two_seventy << endl;
    }
}
