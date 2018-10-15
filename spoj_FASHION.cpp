#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> m;
        vector<int> w;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            m.push_back(temp);
        }

        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            w.push_back(temp);
        }

        sort(m.begin(), m.end());
        sort(w.begin(), w.end());

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += m[i]*w[i];
        }
        cout << sum << endl;
    }

    return 0;
}
