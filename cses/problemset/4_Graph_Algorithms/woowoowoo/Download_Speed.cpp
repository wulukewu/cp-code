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

long long dinic(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (long long pushed = dfs(s, t, 1e18)) flow += pushed;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    level.assign(n + 1, 0);
    ptr.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; long long c; cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    cout << dinic(1, n) << "\n";
    return 0;
}
