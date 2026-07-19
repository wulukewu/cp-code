#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> parent(n+1, 0), depth(n+1, 0), order;
    order.reserve(n);
    vector<pair<int,int>> st;
    st.push_back({1, 0});
    parent[1] = -1;
    while (!st.empty()) {
        auto [u, p] = st.back(); st.pop_back();
        order.push_back(u);
        for (int v : g[u]) if (v != p) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            st.push_back({v, u});
        }
    }
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (depth[a] != depth[b]) return depth[a] > depth[b];
        return a < b;
    });
    vector<int> closest(n+1, 1e9);
    vector<int> ans;
    for (int u : order) {
        bool ok = true;
        int v = u;
        for (int dist = 0; dist < d && v != -1; v = parent[v], dist++) {
            if (closest[v] + dist < d) { ok = false; break; }
        }
        if (!ok) continue;
        ans.push_back(u);
        closest[u] = 0;
        v = parent[u];
        for (int dist = 1; dist < d && v != -1; v = parent[v], dist++) {
            if (dist < closest[v]) closest[v] = dist;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i+1==(int)ans.size()];
    return 0;
}
