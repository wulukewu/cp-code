#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, w;
    bool operator<(const Edge &o) const { return w < o.w; }
};

vector<int> parent, rnk;

int find(int x) {
    while (parent[x] != x) parent[x] = parent[parent[x]], x = parent[x];
    return x;
}

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].a >> edges[i].b >> edges[i].w;
    sort(edges.begin(), edges.end());
    parent.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
    long long cost = 0;
    int comp = n;
    for (auto &e : edges) {
        if (unite(e.a, e.b)) {
            cost += e.w;
            comp--;
        }
    }
    if (comp > 1) cout << "IMPOSSIBLE\n";
    else cout << cost << "\n";
    return 0;
}
