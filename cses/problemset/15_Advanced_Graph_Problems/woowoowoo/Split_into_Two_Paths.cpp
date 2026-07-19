#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    vector<int> matchL(n+1, 0), matchR(n+1, 0), dist(n+1, 0);
    auto bfs = [&]() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (!matchL[u]) { dist[u] = 0; q.push(u); }
            else dist[u] = INF;
        }
        dist[0] = INF;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] < dist[0]) {
                for (int v : g[u]) {
                    if (dist[matchR[v]] == INF) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
                }
            }
        }
        return dist[0] != INF;
    };
    function<bool(int)> dfs = [&](int u) {
        if (!u) return true;
        for (int v : g[u]) {
            if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = INF;
        return false;
    };
    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (!matchL[u] && dfs(u)) matching++;
        }
    }
    int paths = n - matching;
    if (paths > 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> nxt(n+1, 0);
    for (int v = 1; v <= n; v++) if (matchR[v]) nxt[matchR[v]] = v;
    vector<bool> used(n+1, false);
    vector<vector<int>> result;
    for (int s = 1; s <= n; s++) {
        if (nxt[s] && !matchR[s]) {
            vector<int> path;
            for (int u = s; u; u = nxt[u]) {
                path.push_back(u);
                used[u] = true;
            }
            result.push_back(path);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            result.push_back({i});
            used[i] = true;
        }
    }
    while (result.size() < 2) result.push_back({});
    for (int i = 0; i < 2; i++) {
        if (result[i].empty()) cout << "0\n";
        else {
            cout << result[i].size();
            for (int v : result[i]) cout << " " << v;
            cout << "\n";
        }
    }
    return 0;
}
