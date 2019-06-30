#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

// failed because didn't allocate enough memory
bool visited[100001];
bool has_cat[100001];
vector<int> tree[100001];

int traverse(int start, int limit, int num_cats) {
    if (visited[start]) return 0;
    visited[start] = true;

    // consecutive cats, so reset to 0 when not consecutive.
    // once its passed the limit then no longer reset because this path
    // is doomed.
    if (has_cat[start]) {
        num_cats += 1;
    } else if (num_cats <= limit) {
        num_cats = 0;
    }

    if (tree[start].size() == 1 && start != 0) {
        if (num_cats > limit) return 0;
        return 1;
    }

    int result = 0;
    for(int i=0; i<tree[start].size(); i++) {
        result += traverse(tree[start][i], limit, num_cats);
    }
    return result;
}

int main() {
    memset(visited, 0, sizeof(visited));
    memset(has_cat, 0, sizeof(has_cat));

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> has_cat[i];
    }

    int x,y;
    for (int i=0; i<n-1; i++) {
        cin >> x >> y;
        tree[x-1].push_back(y-1);
        tree[y-1].push_back(x-1);
    }

    cout << traverse(0, m, 0) << endl;
    return 0;
}
