#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long sum, best;
};

struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    Node combine(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.best = max(left.best, left.sum + right.best);
        return res;
    }
    void build(int v, int l, int r, vector<long long>& a) {
        if (l == r) {
            tree[v] = {a[l], max(0LL, a[l])};
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
    void update(int v, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[v] = {val, max(0LL, val)};
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(v * 2, l, m, pos, val);
        else update(v * 2 + 1, m + 1, r, pos, val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
    Node query(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return {0, 0};
        if (ql <= l && r <= qr) return tree[v];
        int m = (l + r) / 2;
        return combine(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seg.update(1, 0, n - 1, x - 1, y);
        } else {
            cout << seg.query(1, 0, n - 1, x - 1, y - 1).best << '\n';
        }
    }
    return 0;
}
