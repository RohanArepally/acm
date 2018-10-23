#include<iostream>

using namespace std;

int main() {
    int in = 0;
    while (in != 42) {
        cin >> in;
        if (in == 42) break;
        cout << in << endl;
    }
}