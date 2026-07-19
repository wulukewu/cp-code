#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> val, tin, tout;
vector<long long> bit;
int timer;

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++timer;
}

void add(int idx, long long delta) {
    while (idx < (int)bit.size()) bit[idx] += delta, idx += idx & -idx;
}

long long sum(int idx) {
    long long s = 0;
    while (idx > 0) s += bit[idx], idx -= idx & -idx;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    adj.assign(n + 1, {});
    val.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    bit.assign(2 * n + 5, 0);
    timer = 0;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        add(tin[i], val[i]);
        add(tout[i], -val[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            long long delta = x - val[s];
            val[s] = x;
            add(tin[s], delta);
            add(tout[s], -delta);
        } else {
            int s; cin >> s;
            cout << sum(tin[s]) << "\n";
        }
    }
    return 0;
}
