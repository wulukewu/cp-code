#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), radj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<int> order; order.reserve(n);
    vector<bool> vis(n+1, false);
    for (int s = 1; s <= n; s++) {
        if (vis[s]) continue;
        stack<pair<int,int>> st;
        st.push({s, 0});
        vis[s] = true;
        while (!st.empty()) {
            auto [u, idx] = st.top(); st.pop();
            if (!idx) {
                st.push({u, 1});
                for (int v : adj[u]) if (!vis[v]) { vis[v] = true; st.push({v, 0}); }
            } else {
                order.push_back(u);
            }
        }
    }
    vector<int> comp(n+1, -1);
    vector<vector<int>> comps;
    for (int i = n-1; i >= 0; i--) {
        int u = order[i];
        if (comp[u] != -1) continue;
        int cid = comps.size();
        comps.push_back({});
        stack<int> st;
        st.push(u);
        comp[u] = cid;
        while (!st.empty()) {
            int x = st.top(); st.pop();
            comps[cid].push_back(x);
            for (int y : radj[x]) if (comp[y] == -1) { comp[y] = cid; st.push(y); }
        }
    }
    int C = comps.size();
    if (C == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> indeg(C, 0), outdeg(C, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            int cu = comp[u], cv = comp[v];
            if (cu != cv) { outdeg[cu]++; indeg[cv]++; }
        }
    }
    vector<int> sources, sinks;
    for (int i = 0; i < C; i++) {
        if (!indeg[i]) sources.push_back(comps[i].back());
        if (!outdeg[i]) sinks.push_back(comps[i].back());
    }
    int k = max((int)sources.size(), (int)sinks.size());
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        int from = sinks[i % sinks.size()];
        int to = sources[i % sources.size()];
        cout << from << " " << to << "\n";
    }
    return 0;
}
