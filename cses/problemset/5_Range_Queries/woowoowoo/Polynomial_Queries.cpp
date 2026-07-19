#include <iostream>
#include <vector>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree, lazyA, lazyB;
    SegTree(vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        lazyA.resize(4 * n, 0);
        lazyB.resize(4 * n, 0);
        build(1, 0, n - 1, a);
    }
    void build(int v, int l, int r, vector<long long>& a) {
        if (l == r) {
            tree[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    long long sum1(long long n) {
        return n * (n + 1) / 2;
    }
    void apply(int v, int l, int r, long long a, long long b) {
        tree[v] += a * sum1(r - l + 1) + b * (r - l + 1);
        lazyA[v] += a;
        lazyB[v] += b;
    }
    void push(int v, int l, int r) {
        if (lazyA[v] != 0 || lazyB[v] != 0) {
            int m = (l + r) / 2;
            apply(v * 2, l, m, lazyA[v], lazyB[v]);
            apply(v * 2 + 1, m + 1, r, lazyA[v], lazyB[v] + lazyA[v] * (m - l + 1));
            lazyA[v] = 0;
            lazyB[v] = 0;
        }
    }
    void update(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, 1, l - ql);
            return;
        }
        push(v, l, r);
        int m = (l + r) / 2;
        update(v * 2, l, m, ql, qr);
        update(v * 2 + 1, m + 1, r, ql, qr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    long long query(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[v];
        push(v, l, r);
        int m = (l + r) / 2;
        return query(v * 2, l, m, ql, qr) + query(v * 2 + 1, m + 1, r, ql, qr);
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
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            seg.update(1, 0, n - 1, l - 1, r - 1);
        } else {
            cout << seg.query(1, 0, n - 1, l - 1, r - 1) << '\n';
        }
    }
    return 0;
}
