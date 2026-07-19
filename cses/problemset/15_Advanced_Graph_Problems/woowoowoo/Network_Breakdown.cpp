#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> p, r;
    int comps;
    DSU(int n) : p(n + 1), r(n + 1, 0), comps(n) {
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
        comps--;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> edges(m);
    map<pair<int,int>,int> edge_id;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edges[i] = {a, b};
        edge_id[{a, b}] = i;
    }
    vector<int> del(k);
    vector<int> alive(m, 1);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int idx = edge_id[{a, b}];
        del[i] = idx;
        alive[idx] = 0;
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        if (alive[i]) dsu.unite(edges[i].first, edges[i].second);
    }
    vector<int> ans(k);
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = dsu.comps;
        dsu.unite(edges[del[i]].first, edges[del[i]].second);
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << (i == k - 1 ? "\n" : " ");
    }
    return 0;
}
