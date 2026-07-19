#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ull = unsigned long long;

map<vector<ull>, ull> hashes;

int dfs_sz(int u, int p, vector<vector<int>>& adj, vector<int>& sz) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) sz[u] += dfs_sz(v, u, adj, sz);
    return sz[u];
}

int find_centroid(int u, int p, int total, vector<vector<int>>& adj, vector<int>& sz) {
    for (int v : adj[u]) if (v != p && sz[v] > total/2) return find_centroid(v, u, total, adj, sz);
    return u;
}

ull dfs_hash(int u, int p, vector<vector<int>>& adj) {
    vector<ull> child;
    for (int v : adj[u]) if (v != p) child.push_back(dfs_hash(v, u, adj));
    sort(child.begin(), child.end());
    if (!hashes.count(child)) hashes[child] = hashes.size() + 1;
    return hashes[child];
}

ull tree_hash(int n, vector<vector<int>>& adj) {
    vector<int> sz(n+1, 0);
    dfs_sz(1, 0, adj, sz);
    int c1 = find_centroid(1, 0, n, adj, sz);
    sz.assign(n+1, 0);
    dfs_sz(c1, 0, adj, sz);
    int c2 = find_centroid(c1, 0, n, adj, sz);
    ull h1 = dfs_hash(c1, 0, adj);
    ull h2 = c1 == c2 ? h1 : dfs_hash(c2, 0, adj);
    return min(h1, h2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj1(n+1), adj2(n+1);
        for (int i = 1; i < n; i++) { int a, b; cin >> a >> b; adj1[a].push_back(b); adj1[b].push_back(a); }
        for (int i = 1; i < n; i++) { int a, b; cin >> a >> b; adj2[a].push_back(b); adj2[b].push_back(a); }
        ull h1 = tree_hash(n, adj1);
        ull h2 = tree_hash(n, adj2);
        cout << (h1 == h2 ? "YES" : "NO") << "\n";
    }
    return 0;
}
