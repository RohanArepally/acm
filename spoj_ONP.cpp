#include <iostream>
#include <stack>

using namespace std;

const string ops = "+*^/-";

int main() {
    int t;
    cin >> t;
    stack<char> s;

    while(t--) {
        string line;
        cin >> line;
        string result = "";

        for(int i=0; i<line.size(); i++) {
            // need to check if stack is empty or well seg fault on .top()
            if (line[i] == ')' && !s.empty()) {
                char op = s.top();
                s.pop();
                result += op;
            // need to use npos to check if not found
            } else if (ops.find(line[i]) != string::npos) {
                s.push(line[i]);
            } else if (line[i] != '(' && line[i] != ')') {
                result += line[i];
            }
        }

        // edge case, for expressions like a+b. We don't pop + operator from stack because we don't see a ')'
        // need to handle this case so we check if the stack is non-empty at the end
        if (!s.empty()) {
            char op = s.top();
            s.pop();
            result += op;
        }

        cout << result << endl;
    }
}