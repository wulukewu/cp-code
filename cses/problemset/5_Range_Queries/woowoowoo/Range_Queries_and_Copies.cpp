#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long sum;
    int left, right;
};

struct PST {
    vector<Node> tree;
    vector<int> roots;
    PST() {
        tree.push_back({0, -1, -1});
        roots.push_back(0);
    }
    int build(int l, int r, vector<long long>& a) {
        if (l == r) {
            tree.push_back({a[l], -1, -1});
            return tree.size() - 1;
        }
        int m = (l + r) / 2;
        int lc = build(l, m, a);
        int rc = build(m + 1, r, a);
        tree.push_back({tree[lc].sum + tree[rc].sum, lc, rc});
        return tree.size() - 1;
    }
    int update(int v, int l, int r, int pos, long long val) {
        if (l == r) {
            tree.push_back({val, -1, -1});
            return tree.size() - 1;
        }
        int m = (l + r) / 2;
        int lc = tree[v].left, rc = tree[v].right;
        if (pos <= m) {
            int nlc = update(lc, l, m, pos, val);
            tree.push_back({tree[nlc].sum + tree[rc].sum, nlc, rc});
        } else {
            int nrc = update(rc, m + 1, r, pos, val);
            tree.push_back({tree[lc].sum + tree[nrc].sum, lc, nrc});
        }
        return tree.size() - 1;
    }
    long long query(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[v].sum;
        int m = (l + r) / 2;
        return query(tree[v].left, l, m, ql, qr) + query(tree[v].right, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    PST pst;
    pst.roots[0] = pst.build(0, n - 1, a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, pos;
            long long x;
            cin >> k >> pos >> x;
            k--; pos--;
            int newRoot = pst.update(pst.roots[k], 0, n - 1, pos, x);
            pst.roots[k] = newRoot;
        } else if (t == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            k--; l--; r--;
            cout << pst.query(pst.roots[k], 0, n - 1, l, r) << '\n';
        } else {
            int k;
            cin >> k;
            k--;
            pst.roots.push_back(pst.roots[k]);
        }
    }
    return 0;
}
