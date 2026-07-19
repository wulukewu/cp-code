#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> tin(n, -1), low(n);
    vector<bool> isArt(n);
    int timer = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && p != -1) isArt[u] = true;
                children++;
            }
        }
        if (p == -1 && children > 1) isArt[u] = true;
    };
    for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) if (isArt[i]) cnt++;
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) if (isArt[i]) cout << i + 1 << "\n";
    return 0;
}
