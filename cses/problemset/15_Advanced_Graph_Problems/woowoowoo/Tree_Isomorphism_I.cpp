#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ull = unsigned long long;

map<vector<ull>, ull> hashes;

ull dfs_hash(int u, int p, vector<vector<int>>& adj) {
    vector<ull> child;
    for (int v : adj[u]) if (v != p) child.push_back(dfs_hash(v, u, adj));
    sort(child.begin(), child.end());
    if (!hashes.count(child)) hashes[child] = hashes.size() + 1;
    return hashes[child];
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
        ull h1 = dfs_hash(1, 0, adj1);
        ull h2 = dfs_hash(1, 0, adj2);
        cout << (h1 == h2 ? "YES" : "NO") << "\n";
    }
    return 0;
}
