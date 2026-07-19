#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1), radj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        radj[b].push_back({a, c});
    }
    auto dijkstra = [&](int s, vector<vector<pair<int,int>>> &g) {
        vector<ll> dist(n+1, 1e18);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto &[v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    vector<ll> dist1 = dijkstra(1, adj);
    vector<ll> distN = dijkstra(n, radj);
    ll shortest = dist1[n];
    vector<vector<int>> dag(n+1), rdag(n+1);
    for (int u = 1; u <= n; u++) {
        if (dist1[u] > shortest) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist1[u] + w == dist1[v] && dist1[v] + distN[v] == shortest) {
                dag[u].push_back(v);
                rdag[v].push_back(u);
            }
        }
    }
    vector<int> dfn(n+1, 0), order(n+1, 0), parent(n+1, 0), semi(n+1, 0), idom(n+1, 0), link(n+1, 0), best(n+1, 0);
    vector<vector<int>> bucket(n+1);
    int timer = 0;
    auto dfs = [&](int s) {
        vector<pair<int,int>> st;
        st.push_back({s, 0});
        while (!st.empty()) {
            auto [u, idx] = st.back(); st.pop_back();
            if (idx == 0) {
                dfn[u] = ++timer;
                order[timer] = u;
                semi[u] = timer;
                best[u] = timer;
                st.push_back({u, 1});
                for (int v : dag[u]) {
                    if (!dfn[v]) {
                        parent[v] = u;
                        st.push_back({v, 0});
                    }
                }
            }
        }
    };
    dfs(1);
    if (!dfn[n]) {
        cout << "0\n";
        return 0;
    }
    auto find = [&](int v) {
        vector<int> path;
        while (link[v] != 0) {
            path.push_back(v);
            v = link[v];
        }
        int root = v;
        for (int i = (int)path.size()-1; i >= 0; i--) {
            int x = path[i];
            if (semi[best[x]] < semi[root]) root = best[x];
            best[x] = root;
            link[x] = root;
        }
        return root;
    };
    for (int i = timer; i >= 2; i--) {
        int w = order[i];
        for (int v : rdag[w]) {
            if (dfn[v]) {
                int u = find(v);
                semi[w] = min(semi[w], semi[u]);
            }
        }
        bucket[order[semi[w]]].push_back(w);
        link[w] = parent[w];
        for (int v : bucket[parent[w]]) {
            int u = find(v);
            idom[v] = (semi[u] < semi[v] ? u : parent[w]);
        }
        bucket[parent[w]].clear();
    }
    for (int i = 2; i <= timer; i++) {
        int w = order[i];
        if (idom[w] != order[semi[w]]) idom[w] = idom[idom[w]];
    }
    idom[1] = 0;
    vector<int> ans;
    for (int v = n; v != 0; v = idom[v]) ans.push_back(v);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i+1==(int)ans.size()];
    return 0;
}
