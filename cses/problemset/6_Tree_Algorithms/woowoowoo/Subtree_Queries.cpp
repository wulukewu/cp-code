#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> val, tin, tout;
vector<long long> tree;
int timer;

void dfs(int u, int p) {
    tin[u] = ++timer;
    tree[timer] = val[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer;
}

long long query(int idx) {
    long long s = 0;
    while (idx > 0) s += tree[idx], idx -= idx & -idx;
    return s;
}

void add(int idx, long long delta) {
    while (idx < (int)tree.size()) tree[idx] += delta, idx += idx & -idx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    adj.assign(n + 1, {});
    val.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    tree.assign(n + 2, 0);
    timer = 0;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        long long old = query(tin[i]);
        add(tin[i], val[i] - (old - query(tin[i] - 1)));
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            long long cur = query(tin[s]) - query(tin[s] - 1);
            long long delta = x - cur;
            add(tin[s], delta);
        } else {
            int s; cin >> s;
            cout << query(tout[s]) - query(tin[s] - 1) << "\n";
        }
    }
    return 0;
}
