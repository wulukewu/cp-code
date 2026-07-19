#include <iostream>
#include <vector>
using namespace std;

struct BIT2D {
    int n;
    vector<vector<int>> tree;
    BIT2D(int n) : n(n), tree(n + 1, vector<int>(n + 1, 0)) {}
    void add(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                tree[i][j] += val;
    }
    int sum(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                res += tree[i][j];
        return res;
    }
    int query(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    BIT2D bit(n);
    vector<vector<char>> grid(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                bit.add(i, j, 1);
            }
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int y, x;
            cin >> y >> x;
            if (grid[y][x] == '*') {
                grid[y][x] = '.';
                bit.add(y, x, -1);
            } else {
                grid[y][x] = '*';
                bit.add(y, x, 1);
            }
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << bit.query(y1, x1, y2, x2) << '\n';
        }
    }
    return 0;
}
