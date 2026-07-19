#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 2, 0) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }
    int sum(int idx) {
        int res = 0;
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> last(vals.size() + 1, 0);
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    BIT bit(n);
    vector<int> ans(q);
    for (int r = 1; r <= n; r++) {
        int val = lower_bound(vals.begin(), vals.end(), a[r]) - vals.begin() + 1;
        if (last[val]) bit.add(last[val], -1);
        bit.add(r, 1);
        last[val] = r;
        for (auto [l, idx] : queries[r]) {
            ans[idx] = bit.sum(r) - bit.sum(l - 1);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
    return 0;
}
