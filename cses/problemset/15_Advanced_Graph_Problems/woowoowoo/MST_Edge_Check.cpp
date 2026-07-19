#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w, a, b};
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return get<0>(edges[i]) < get<0>(edges[j]);
    });
    vector<bool> ans(m, false);
    DSU dsu(n);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && get<0>(edges[order[j]]) == get<0>(edges[order[i]])) j++;
        for (int t = i; t < j; t++) {
            int idx = order[t];
            auto [w, a, b] = edges[idx];
            if (dsu.find(a) != dsu.find(b)) ans[idx] = true;
        }
        for (int t = i; t < j; t++) {
            int idx = order[t];
            auto [w, a, b] = edges[idx];
            dsu.unite(a, b);
        }
        i = j;
    }
    for (int i = 0; i < m; i++) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}
