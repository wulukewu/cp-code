#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adjMask(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adjMask[a] |= 1 << b;
        adjMask[b] |= 1 << a;
    }
    int N = 1 << n;
    vector<bool> indep(N, false);
    indep[0] = true;
    for (int mask = 1; mask < N; mask++) {
        int lsb = mask & -mask;
        int u = __builtin_ctz(lsb);
        int rest = mask ^ lsb;
        if (indep[rest] && (adjMask[u] & rest) == 0) indep[mask] = true;
    }
    vector<int> dp(N, n+1), choice(N, 0);
    dp[0] = 0;
    for (int mask = 1; mask < N; mask++) {
        for (int sub = mask; sub; sub = (sub-1) & mask) {
            if (indep[sub] && dp[mask ^ sub] + 1 < dp[mask]) {
                dp[mask] = dp[mask ^ sub] + 1;
                choice[mask] = sub;
            }
        }
    }
    int full = N - 1;
    int k = dp[full];
    cout << k << "\n";
    vector<int> col(n);
    int cur = full;
    while (cur) {
        int sub = choice[cur];
        for (int u = 0; u < n; u++) if (sub & (1 << u)) col[u] = k;
        k--;
        cur ^= sub;
    }
    for (int i = 0; i < n; i++) cout << col[i] << " \n"[i+1==n];
    return 0;
}
