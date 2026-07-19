#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; i++) p[i] = i;
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    ll unite(int a, int b, ll w, ll &ans) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        ans += (ll)sz[a] * sz[b] * w;
        p[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.rbegin(), edges.rend());
    DSU dsu(n);
    ll ans = 0;
    for (auto &[w, p] : edges) {
        dsu.unite(p.first, p.second, w, ans);
    }
    cout << ans << "\n";
    return 0;
}
