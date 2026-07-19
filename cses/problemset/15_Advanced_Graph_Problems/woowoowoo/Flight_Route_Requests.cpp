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
    vector<bool> vis(n+1, false);
    vector<int> order;
    order.reserve(n);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        stack<pair<int,int>> st;
        st.push({i, 0});
        vis[i] = true;
        while (!st.empty()) {
            auto [u, idx] = st.top(); st.pop();
            if (idx == 0) {
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
    long long ans = 0;
    for (auto &c : comps) if (c.size() > 1) ans += c.size();
    vector<vector<int>> cUnd(C);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            int cu = comp[u], cv = comp[v];
            if (cu != cv) {
                cUnd[cu].push_back(cv);
                cUnd[cv].push_back(cu);
            }
        }
    }
    vector<bool> cvis(C, false);
    int dagComp = 0;
    for (int i = 0; i < C; i++) {
        if (cvis[i]) continue;
        dagComp++;
        stack<int> st;
        st.push(i);
        cvis[i] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : cUnd[u]) if (!cvis[v]) { cvis[v] = true; st.push(v); }
        }
    }
    ans += C - dagComp;
    cout << ans << "\n";
    return 0;
}
