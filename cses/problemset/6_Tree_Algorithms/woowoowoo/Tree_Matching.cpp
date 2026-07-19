#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    adj.assign(n + 1, {});
    dp.assign(n + 1, vector<int>(2, 0));
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
