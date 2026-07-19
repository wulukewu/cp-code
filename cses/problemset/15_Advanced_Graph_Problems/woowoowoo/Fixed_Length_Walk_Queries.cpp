#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<tuple<int,int,int>>> qs(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        qs[a].push_back({b, x, i});
    }
    vector<string> ans(q);
    for (int s = 1; s <= n; s++) {
        if (qs[s].empty()) continue;
        vector<short> dist0(n + 1, -1), dist1(n + 1, -1);
        queue<pair<int,int>> qu;
        dist0[s] = 0;
        qu.push({s, 0});
        while (!qu.empty()) {
            auto [u, p] = qu.front();
            qu.pop();
            int d = (p == 0 ? dist0[u] : dist1[u]);
            for (int v : adj[u]) {
                if (p == 0) {
                    if (dist1[v] == -1) {
                        dist1[v] = d + 1;
                        qu.push({v, 1});
                    }
                } else {
                    if (dist0[v] == -1) {
                        dist0[v] = d + 1;
                        qu.push({v, 0});
                    }
                }
            }
        }
        for (auto [b, x, idx] : qs[s]) {
            int d = (x % 2 == 0) ? dist0[b] : dist1[b];
            if (d != -1 && d <= x) ans[idx] = "YES";
            else ans[idx] = "NO";
        }
    }
    for (auto &s : ans) cout << s << "\n";
    return 0;
}
