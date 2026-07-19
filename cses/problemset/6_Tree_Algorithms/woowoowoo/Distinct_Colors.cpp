#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> col, ans;
vector<set<int>> st;

void dfs(int u, int p) {
    st[u].insert(col[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (st[v].size() > st[u].size()) swap(st[u], st[v]);
        st[u].insert(st[v].begin(), st[v].end());
    }
    ans[u] = st[u].size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    adj.assign(n + 1, {});
    col.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    st.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
