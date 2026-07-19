#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int n) : n(n), tree(4 * n) {
        build(1, 0, n - 1);
    }
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m);
        build(node * 2 + 1, m + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    int query(int node, int l, int r, int k) {
        if (l == r) return l;
        int m = (l + r) / 2;
        if (k <= tree[node * 2]) return query(node * 2, l, m, k);
        return query(node * 2 + 1, m + 1, r, k - tree[node * 2]);
    }
    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) update(node * 2, l, m, idx);
        else update(node * 2 + 1, m + 1, r, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    int total() { return tree[1]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    SegTree st(n);
    int idx = k % n;
    for (int i = 0; i < n; i++) {
        int p = st.query(1, 0, n - 1, idx + 1);
        cout << p + 1 << ' ';
        st.update(1, 0, n - 1, p);
        if (st.total() == 0) break;
        idx = (idx + k) % st.total();
    }
    cout << '\n';
    return 0;
}
