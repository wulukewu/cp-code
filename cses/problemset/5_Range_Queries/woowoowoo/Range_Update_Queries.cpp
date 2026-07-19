#include <iostream>
#include <vector>
using namespace std;

struct BIT {
    int n;
    vector<long long> tree;
    BIT(int n) : n(n), tree(n + 2, 0) {}
    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }
    long long sum(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    BIT bit(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            long long u;
            cin >> l >> r >> u;
            bit.add(l, u);
            bit.add(r + 1, -u);
        } else {
            int k;
            cin >> k;
            cout << a[k] + bit.sum(k) << '\n';
        }
    }
    return 0;
}
