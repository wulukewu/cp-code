#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 200005;
const int LOG = 18;
const int INF = 1e9;

int up[N][LOG], mn[N][LOG], depth[N], dist_to_coin[N];
vector<int> adj[N];
int n, q;

void bfs_coins(vector<int>& coins) {
    fill(dist_to_coin, dist_to_coin + n + 1, INF);
    queue<int> qq;
    for (int c : coins) { dist_to_coin[c] = 0; qq.push(c); }
    while (!qq.empty()) {
        int u = qq.front(); qq.pop();
        for (int v : adj[u]) if (dist_to_coin[v] > dist_to_coin[u] + 1) {
            dist_to_coin[v] = dist_to_coin[u] + 1;
            qq.push(v);
        }
    }
}

void dfs(int u, int p) {
    up[u][0] = p;
    mn[u][0] = dist_to_coin[u];
    for (int k = 1; k < LOG; k++) {
        up[u][k] = up[up[u][k-1]][k-1];
        mn[u][k] = min(mn[u][k-1], mn[up[u][k-1]][k-1]);
    }
    for (int v : adj[u]) if (v != p) { depth[v] = depth[u] + 1; dfs(v, u); }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) if (diff >> i & 1) u = up[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) if (up[u][i] && up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
    return up[u][0];
}

int query_min(int u, int v) {
    int diff = depth[u] - depth[v];
    int ans = INF;
    for (int i = 0; i < LOG; i++) if (diff >> i & 1) {
        ans = min(ans, mn[u][i]);
        u = up[u][i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<int> coins;
    for (int i = 1; i <= n; i++) { int c; cin >> c; if (c) coins.push_back(i); }
    for (int i = 1; i < n; i++) { int a, b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a); }
    if (coins.empty()) { while (q--) cout << "0\n"; return 0; }
    bfs_coins(coins);
    dfs(1, 0);
    while (q--) {
        int a, b; cin >> a >> b;
        int l = lca(a, b);
        int d = depth[a] + depth[b] - 2 * depth[l];
        int m = min({query_min(a, l), query_min(b, l), dist_to_coin[l]});
        cout << d + 2 * m << "\n";
    }
    return 0;
}
