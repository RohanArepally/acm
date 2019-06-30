#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int length, sum;
    cin >> length >> sum;

    // forgot this edgecase when maximum and minimum number can both be 0.
    // only solved for numbers that began with 1,..
    if (sum == 0 && length == 1 ) {
        cout << "0 0" << endl;
        return 0;
    }
    if (sum == 0 || length * 9 < sum) {
        cout << "-1 -1" << endl;
        return 0;
    }

    vector<int> num(length, 0);
    num[0] = 1;

    // calculate max
    int index=0;
    for (int i=0; i<sum-1; i++) {
        if (num[index] == 9) {
            index++;
        }
        num[index]++;
    }

    vector<int> min_num(length, 0);
    min_num[0] = 1;

    index=length-1;
    for (int i=0; i<sum-1; i++) {
        if (min_num[index] == 9) {
            index--;
        }
        min_num[index]++;
    }

    for (int i=0; i<length; i++) {
        cout << min_num[i];
    }
    cout << " ";
    for (int i=0; i<length; i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
