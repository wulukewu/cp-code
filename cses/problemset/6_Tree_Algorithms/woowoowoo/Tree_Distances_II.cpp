#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<long long> sz, ans;
int n;

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        ans[1] += sz[v];
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + n - 2 * sz[v];
        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    adj.assign(n + 1, {});
    sz.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
