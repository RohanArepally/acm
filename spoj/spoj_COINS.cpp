#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> mp;

long long coin(long long num) {
    if (mp.count(num) > 0) {
        return mp[num];
    }
    if(num/4 == 0) return num;
    long long result = max(num, coin(num/4) + coin(num/3) + coin(num/2));
    mp[num] = result;
    return result;
}

int main() {
    long n;
    while(cin >> n) {
        cout << coin(n) << endl;
    }
    return 0;
}

