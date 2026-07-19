#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge {
    int to, rev;
    long long cap;
};

vector<vector<Edge>> adj;
vector<int> level, ptr;

void add_edge(int u, int v, long long cap) {
    adj[u].push_back({v, (int)adj[v].size(), cap});
    adj[v].push_back({u, (int)adj[u].size() - 1, 0});
}

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &e : adj[u]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

long long dfs(int u, int t, long long f) {
    if (u == t) return f;
    for (int &i = ptr[u]; i < (int)adj[u].size(); i++) {
        Edge &e = adj[u][i];
        if (e.cap > 0 && level[e.to] == level[u] + 1) {
            long long pushed = dfs(e.to, t, min(f, e.cap));
            if (pushed > 0) {
                e.cap -= pushed;
                adj[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    int S = 0, T = n + m + 1;
    adj.assign(T + 1, {});
    level.assign(T + 1, 0);
    ptr.assign(T + 1, 0);
    for (int i = 1; i <= n; i++) add_edge(S, i, 1);
    for (int i = 1; i <= m; i++) add_edge(n + i, T, 1);
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        add_edge(a, n + b, 1);
    }
    long long flow = 0;
    while (bfs(S, T)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (long long pushed = dfs(S, T, 1e18)) flow += pushed;
    }
    cout << flow << "\n";
    for (int u = 1; u <= n; u++) {
        for (auto &e : adj[u]) {
            if (e.to > n && e.to <= n + m && e.cap == 0) {
                cout << u << " " << e.to - n << "\n";
            }
        }
    }
    return 0;
}
