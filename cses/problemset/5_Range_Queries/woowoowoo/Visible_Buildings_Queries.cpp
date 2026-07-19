#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Fenwick {
    int n;
    vector<ll> tree;
    void init(int _n) {
        n = _n;
        tree.resize(n, 0);
    }
    void add(int pos, ll val) {
        for (int i = pos + 1; i <= n; i += i & -i)
            tree[i - 1] += val;
    }
    ll sum(int pos) {
        ll res = 0;
        for (int i = pos + 1; i > 0; i -= i & -i)
            res += tree[i - 1];
        return res;
    }
    ll query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<vector<pair<int,int>>> queries(n);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        queries[a].push_back({b, i});
    }
    Fenwick fen;
    fen.init(n);
    vector<int> ans(q);
    set<pair<int,int>> active;
    for (int i = n - 1; i >= 0; i--) {
        auto it = active.upper_bound({h[i], 1000000000});
        for (auto nxt = active.begin(); nxt != it; nxt++) {
            fen.add(nxt->second, -1);
        }
        fen.add(i, 1);
        active.erase(active.begin(), it);
        active.insert({h[i], i});
        for (auto &p : queries[i]) {
            ans[p.second] = fen.query(i, p.first);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}
