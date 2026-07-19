#include <iostream>
#include <vector>

using namespace std;

const int mxN = 100005;
const int MOD = 1000000007;
vector<int> adj[mxN];
int vis[mxN], cnt;

long long modpow(long long x, long long y) {
    long long ans = 1;
    while (y > 0) {
        if (y & 1) ans = ans * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

void dfs(int s, int p) {
    if (vis[s]) return;
    vis[s] = 1;
    for (auto i : adj[s]) if (i != p) {
        if (vis[i] == 1) cnt++;
        else if (vis[i] == 0) dfs(i, s);
    }
    vis[s] = 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) if (vis[i] == 0) {
        cnt = 0;
        dfs(i, 0);
        ans = ans * modpow(2, cnt) % MOD;
    }
    cout << ans << "
";
    return 0;
}
