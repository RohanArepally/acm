#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s

bool flags[3000];

int main() {
    int n;
    while(cin >> n) {
        vi v;
        memset(flags, false, sizeof(flags));
        bool jolly = true;

        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        for(int i=1; i<n; i++) {
            int diff = abs(v[i] - v[i-1]);

            if (diff > n-1 ||  diff < 1) {
                jolly = false;
                break;
            } else if(flags[diff]) {
                jolly = false;
                break;
            }

            flags[diff] = true;
        }

        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            // Need to check to make sure output is exactly as stated
            // got 2 WAs because used 'Jolly' instead of 'jolly'
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}
