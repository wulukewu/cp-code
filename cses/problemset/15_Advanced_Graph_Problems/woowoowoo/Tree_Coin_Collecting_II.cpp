#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 200005;
const int LOG = 18;

int tin[N], tout[N], timer, up[N][LOG], depth[N];
vector<int> adj[N];
vector<int> coin_nodes;
int n, q;

void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) up[u][i] = up[up[u][i-1]][i-1];
    for (int v : adj[u]) if (v != p) { depth[v] = depth[u] + 1; dfs(v, u); }
    tout[u] = timer;
}

bool is_anc(int u, int v) { return u && tin[u] <= tin[v] && tout[v] <= tout[u]; }

int lca(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--) if (up[u][i] && !is_anc(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) { int c; cin >> c; if (c) coin_nodes.push_back(i); }
    for (int i = 1; i < n; i++) { int a, b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a); }
    dfs(1, 0);
    sort(coin_nodes.begin(), coin_nodes.end(), [&](int x, int y) { return tin[x] < tin[y]; });
    ll base_sum = 0;
    int k = coin_nodes.size();
    for (int i = 0; i < k; i++) base_sum += dist(coin_nodes[i], coin_nodes[(i+1)%k]);
    while (q--) {
        int a, b; cin >> a >> b;
        ll extra = 0;
        bool a_in = binary_search(coin_nodes.begin(), coin_nodes.end(), a, [&](int x, int y) { return tin[x] < tin[y]; });
        bool b_in = binary_search(coin_nodes.begin(), coin_nodes.end(), b, [&](int x, int y) { return tin[x] < tin[y]; });
        if (!a_in) {
            auto it = lower_bound(coin_nodes.begin(), coin_nodes.end(), a, [&](int x, int y) { return tin[x] < tin[y]; });
            int p = (it == coin_nodes.begin()) ? coin_nodes.back() : *(it-1);
            int s = (it == coin_nodes.end()) ? coin_nodes[0] : *it;
            extra += dist(p, a) + dist(a, s) - dist(p, s);
        }
        if (!b_in && b != a) {
            auto it = lower_bound(coin_nodes.begin(), coin_nodes.end(), b, [&](int x, int y) { return tin[x] < tin[y]; });
            int p = (it == coin_nodes.begin()) ? coin_nodes.back() : *(it-1);
            int s = (it == coin_nodes.end()) ? coin_nodes[0] : *it;
            if (!a_in && tin[a] > tin[p] && tin[a] < tin[b]) p = a;
            if (!a_in && tin[a] > tin[b] && tin[a] < tin[s]) s = a;
            extra += dist(p, b) + dist(b, s) - dist(p, s);
        }
        cout << base_sum + extra - dist(a, b) << "\n";
    }
    return 0;
}
