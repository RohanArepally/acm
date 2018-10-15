#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != -1) {
        int sum = 0;
        int num;
        vector<int> v;
        for(int i=0; i<n; i++) {
            cin >> num;
            v.push_back(num);
            sum += num;
        }
        if (sum % n == 0) {
            int moves = 0;
            for (int i=0; i<n; i++) {
                if (v[i] < sum/n) {
                    moves += (sum/n - v[i]);
                }
            }
            cout << moves << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
