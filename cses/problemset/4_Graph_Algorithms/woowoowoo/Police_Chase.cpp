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
vector<bool> vis;

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

void dfs_vis(int u) {
    vis[u] = true;
    for (auto &e : adj[u]) {
        if (e.cap > 0 && !vis[e.to]) dfs_vis(e.to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    level.assign(n + 1, 0);
    ptr.assign(n + 1, 0);
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
        edges.push_back({a, b});
    }
    long long flow = 0;
    while (bfs(1, n)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (long long pushed = dfs(1, n, 1e18)) flow += pushed;
    }
    cout << flow << "\n";
    vis.assign(n + 1, false);
    dfs_vis(1);
    for (int i = 0; i < m; i++) {
        int a = edges[i].first, b = edges[i].second;
        if (vis[a] != vis[b]) cout << a << " " << b << "\n";
    }
    return 0;
}
