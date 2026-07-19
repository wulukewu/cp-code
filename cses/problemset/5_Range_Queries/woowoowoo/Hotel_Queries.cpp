#include <iostream>
#include <vector>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    SegTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    void build(int v, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
    int query(int v, int l, int r, int x) {
        if (tree[v] < x) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        if (tree[v * 2] >= x) return query(v * 2, l, m, x);
        return query(v * 2 + 1, m + 1, r, x);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(v * 2, l, m, pos, val);
        else update(v * 2 + 1, m + 1, r, pos, val);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(a);
    while (q--) {
        int x;
        cin >> x;
        int idx = seg.query(1, 0, n - 1, x);
        if (idx == -1) {
            cout << 0 << '\n';
        } else {
            cout << idx + 1 << '\n';
            a[idx] -= x;
            seg.update(1, 0, n - 1, idx, a[idx]);
        }
    }
    return 0;
}
