#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int to, rev;
    ll cap, cost;
};

struct MCMF {
    int n;
    vector<vector<Edge>> g;
    vector<ll> dist;
    vector<int> pv, pe;
    vector<int> used_edges;
    MCMF(int n) : n(n), g(n), dist(n), pv(n), pe(n) {}
    void add_edge(int from, int to, ll cap, ll cost) {
        g[from].push_back({to, (int)g[to].size(), cap, cost});
        g[to].push_back({from, (int)g[from].size() - 1, 0, -cost});
        if (from == 0 && to == n - 1) used_edges.push_back((int)g[from].size() - 2);
    }
    pair<ll,ll> flow(int s, int t, ll maxf) {
        ll flow = 0, cost = 0;
        while (flow < maxf) {
            fill(dist.begin(), dist.end(), INF);
            fill(pv.begin(), pv.end(), -1);
            fill(pe.begin(), pe.end(), -1);
            dist[s] = 0;
            queue<int> q; q.push(s);
            vector<bool> inq(n, false); inq[s] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop(); inq[u] = false;
                for (int i = 0; i < (int)g[u].size(); i++) {
                    auto &e = g[u][i];
                    if (e.cap > 0 && dist[e.to] > dist[u] + e.cost) {
                        dist[e.to] = dist[u] + e.cost;
                        pv[e.to] = u; pe[e.to] = i;
                        if (!inq[e.to]) { q.push(e.to); inq[e.to] = true; }
                    }
                }
            }
            if (dist[t] == INF) break;
            ll add = maxf - flow;
            for (int v = t; v != s; v = pv[v])
                add = min(add, g[pv[v]][pe[v]].cap);
            flow += add;
            cost += add * dist[t];
            for (int v = t; v != s; v = pv[v]) {
                auto &e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
            }
        }
        if (flow < maxf) return {-1, flow};
        return {cost, flow};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    MCMF mcmf(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        mcmf.add_edge(a, b, 1, 1);
    }
    auto ans = mcmf.flow(0, n - 1, k);
    if (ans.first == -1) { cout << -1 << "\n"; return 0; }
    cout << ans.first << "\n";
    // Reconstruct paths
    for (int d = 0; d < k; d++) {
        vector<int> path;
        int u = 0;
        path.push_back(0);
        while (u != n - 1) {
            for (auto &e : mcmf.g[u]) {
                if (e.cap == 0 && e.cost > 0) {
                    e.cap = -1;
                    u = e.to;
                    break;
                }
            }
            path.push_back(u);
        }
        cout << path.size() << "\n";
        for (int i = 0; i < (int)path.size(); i++)
            cout << path[i] + 1 << (i + 1 == (int)path.size() ? "\n" : " ");
    }
    return 0;
}
