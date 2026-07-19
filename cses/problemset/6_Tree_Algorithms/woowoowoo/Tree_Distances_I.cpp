#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> down1, down2, up, ans;

int dfs_down(int u, int p) {
    down1[u] = down2[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        int d = dfs_down(v, u) + 1;
        if (d > down1[u]) { down2[u] = down1[u]; down1[u] = d; }
        else if (d > down2[u]) down2[u] = d;
    }
    return down1[u];
}

void dfs_up(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        int use = (down1[v] + 1 == down1[u]) ? down2[u] : down1[u];
        up[v] = max(up[u], use) + 1;
        dfs_up(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    adj.assign(n + 1, {});
    down1.assign(n + 1, 0);
    down2.assign(n + 1, 0);
    up.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_down(1, 0);
    dfs_up(1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = max(down1[i], up[i]);
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
