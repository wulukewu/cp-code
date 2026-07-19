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
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
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
    vector<int> pos(m);
    for (int i = 0; i < m; i++) pos[order[i]] = i;
    while (q--) {
        int t;
        cin >> t;
        vector<int> sel(t);
        for (int i = 0; i < t; i++) {
            cin >> sel[i];
            sel[i]--;
            sel[i] = pos[sel[i]];
        }
        sort(sel.begin(), sel.end());
        DSU dsu(n);
        bool ok = true;
        int sidx = 0;
        for (int i = 0; i < m && ok; ) {
            int j = i;
            int w = get<0>(edges[order[i]]);
            while (j < m && get<0>(edges[order[j]]) == w) j++;
            while (sidx < t && sel[sidx] < i) sidx++;
            while (sidx < t && sel[sidx] < j) {
                int idx = order[sel[sidx]];
                auto [w, a, b] = edges[idx];
                if (!dsu.unite(a, b)) {
                    ok = false;
                    break;
                }
                sidx++;
            }
            if (!ok) break;
            for (int k = i; k < j; k++) {
                auto [w, a, b] = edges[order[k]];
                dsu.unite(a, b);
            }
            i = j;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
