#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n = (int) floor(sqrt(1000000000)) + 1;
    int segSize = 100001;
    bool segment[segSize];
    memset(segment, true, sizeof(bool) * segSize);
    vector<int> primes;

    for (int i=2; i<=n; i++) {
        for(int j=i+i; j <= n; j+=i) {
            segment[j] = false;
        }
    }

    // mistakenly thought 1 was prime, need to start indexing at 2
    for (int i=2; i<=n; i++) {
        if (segment[i]) primes.push_back(i);
    }

    int a,b;

    while (t--) {
        cin >> a >> b;
        memset(segment, true, sizeof(bool) * segSize);
        // same 1 isn't prime thing -- 2nd time making mistake
        if(a == 1) segment[0] = false;

        for (auto p: primes) {
            if (p > b) break;

            int lowestMultiple = p * (a / p);
            if (lowestMultiple < a) lowestMultiple += p;
            if (lowestMultiple == p) lowestMultiple += p;

            for (int i = lowestMultiple; i <= b; i += p) {
                int index = i - a;
                segment[index] = false;
            }
        }

        for (int i=a; i<=b; i++) {
            if (segment[i - a]) {
                 cout << i << endl;
            }
        }
        cout << endl;
    }
}