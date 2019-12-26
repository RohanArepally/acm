#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        unordered_map<char, unsigned int> mp;

        int k;
        cin >> k;
        while (k--) {
            char c;
            int amount;
            cin >> c >> amount;
            mp[c] = amount;
        }

        int M;
        cin >> M;

        // when using getline gotta remember to flush the buffer
        // since cin leaves a \n at the end
        cin.ignore();

        while (M--) {
            string L;
            getline(cin, L);
            for (auto c: L) {
                if (mp.count(c) != 0) {
                    sum += mp[c];
                }
            }
        }

        double money = sum / 100.0;
        printf("%.2f$\n", money);
    }

    return 0;
}
