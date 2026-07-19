#include <iostream>
#include <vector>
using namespace std;

int LOG;
vector<vector<int>> up;
vector<int> depth;

int kth_ancestor(int u, int k) {
    if (depth[u] < k) return -1;
    for (int i = LOG; i >= 0; i--)
        if (k & (1 << i))
            u = up[u][i];
    return u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    LOG = 0;
    while ((1 << LOG) <= n) LOG++;
    up.assign(n + 1, vector<int>(LOG + 1, 0));
    depth.assign(n + 1, 0);
    depth[1] = 0;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        up[i][0] = p;
        depth[i] = depth[p] + 1;
    }
    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j-1]][j-1];
    while (q--) {
        int u, k; cin >> u >> k;
        cout << kth_ancestor(u, k) << "\n";
    }
    return 0;
}
