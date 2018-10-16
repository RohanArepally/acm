#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        string s;
        cin >> s;
        vector<char> v;
        for(int i=0; i<s.length(); i++) {
            v.push_back(s[i]);
        }

        bool shouldReverse = false;
        for(int i=0; i<(s.length()/n); i++) {
            if (shouldReverse) {
                int start = i*n;
                int end = start + n;

                // lost time debugging because used v.end() for 2nd param instead of
                // v.begin(). Double check iterator ranges.
                reverse(v.begin()+start, v.begin()+end);

                shouldReverse = false;
            } else {
                shouldReverse = true;
            }
        }

        string result = "";
        for(int i=0; i<n; i++) {
            for(int j=0; j<(s.length()/n); j++) {
                // j*n + i, is a little complicated, maybe better variable names to not
                // make arthmatic errors
                result += v[j*n + i];
            }
        }
        cout << result << endl;
    }
    return 0;
}
