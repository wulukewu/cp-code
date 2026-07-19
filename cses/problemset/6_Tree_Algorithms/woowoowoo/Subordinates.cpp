#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

void dfs(int u) {
    dp[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        dp[u] += dp[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    adj.assign(n + 1, {});
    dp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << dp[i] - 1 << " \n"[i == n];
    return 0;
}
