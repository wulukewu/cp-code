#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent, sz;

int find(int x) {
    while (parent[x] != x) parent[x] = parent[parent[x]], x = parent[x];
    return x;
}

int unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return sz[a];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    int comps = n, max_sz = 1;
    while (m--) {
        int a, b; cin >> a >> b;
        if (find(a) != find(b)) {
            int new_sz = unite(a, b);
            comps--;
            if (new_sz > max_sz) max_sz = new_sz;
        }
        cout << comps << " " << max_sz << "\n";
    }
    return 0;
}
