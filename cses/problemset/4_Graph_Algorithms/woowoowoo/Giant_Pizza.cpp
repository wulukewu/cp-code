#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> vis;
vector<int> order, comp;
int comp_id;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp[u] = comp_id;
    for (int v : radj[u]) if (!vis[v]) dfs2(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    int sz = 2 * m + 2;
    adj.assign(sz, {});
    radj.assign(sz, {});
    auto add_impl = [&](int a, int b) {
        adj[a].push_back(b);
        radj[b].push_back(a);
    };
    for (int i = 0; i < n; i++) {
        char ta, tb;
        int a, b;
        cin >> ta >> a >> tb >> b;
        int na = a * 2, aa = a * 2 + 1;
        int nb = b * 2, bb = b * 2 + 1;
        if (ta == '-') swap(na, aa);
        if (tb == '-') swap(nb, bb);
        add_impl(aa, nb);
        add_impl(bb, na);
    }
    vis.assign(sz, false);
    for (int i = 2; i <= 2 * m + 1; i++) if (!vis[i]) dfs1(i);
    vis.assign(sz, false);
    comp.assign(sz, 0);
    comp_id = 0;
    for (int i = order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (!vis[u]) { comp_id++; dfs2(u); }
    }
    for (int i = 1; i <= m; i++) {
        if (comp[i * 2] == comp[i * 2 + 1]) { cout << "IMPOSSIBLE\n"; return 0; }
    }
    for (int i = 1; i <= m; i++) {
        cout << (comp[i * 2] > comp[i * 2 + 1] ? "+" : "-") << " \n"[i == m];
    }
    return 0;
}
