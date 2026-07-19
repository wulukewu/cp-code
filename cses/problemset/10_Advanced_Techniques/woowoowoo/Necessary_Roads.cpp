#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mxN = 100005;
vector<int> adj[mxN];
vector<pair<int,int>> ans;
int vis[mxN], low[mxN], timer;

void dfs(int s, int p) {
    vis[s] = low[s] = ++timer;
    for (auto i : adj[s]) if (i != p) {
        if (vis[i])
            low[s] = min(low[s], vis[i]);
        else {
            dfs(i, s);
            low[s] = min(low[s], low[i]);
            if (low[i] > vis[s])
                ans.push_back({s, i});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
    cout << ans.size() << "
";
    for (auto [i, j] : ans) cout << i << " " << j << "
";
    return 0;
}
