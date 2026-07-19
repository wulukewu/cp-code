#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<int> dp_memo;

// 記憶化搜索 DFS
int solve(int u) {
    // 順利到達終點關卡
    if (u == n) {
        return 1;
    }
    // 如果該狀態已經計算過，直接回傳
    if (dp_memo[u] != -1) {
        return dp_memo[u];
    }

    long long ways = 0;
    for (int v : adj[u]) {
        ways = (ways + solve(v)) % MOD;
    }

    return dp_memo[u] = ways;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    dp_memo.assign(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 從關卡 1 開始計算路徑總數
    cout << solve(1) << "\n";

    return 0;
}