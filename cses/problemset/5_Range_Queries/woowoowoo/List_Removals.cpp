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
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    int query(int v, int l, int r, int k) {
        if (l == r) return l;
        int m = (l + r) / 2;
        if (k <= tree[v * 2]) return query(v * 2, l, m, k);
        return query(v * 2 + 1, m + 1, r, k - tree[v * 2]);
    }
    void update(int v, int l, int r, int pos) {
        if (l == r) {
            tree[v] = 0;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(v * 2, l, m, pos);
        else update(v * 2 + 1, m + 1, r, pos);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), init(n, 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(init);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int idx = seg.query(1, 0, n - 1, k);
        cout << a[idx] << ' ';
        seg.update(1, 0, n - 1, idx);
    }
    cout << '\n';
    return 0;
}
