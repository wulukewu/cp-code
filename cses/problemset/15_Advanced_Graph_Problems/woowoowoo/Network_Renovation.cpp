#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n1 2\n";
        return 0;
    }
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = 1;
    for (int i = 1; i <= n; i++) if (g[i].size() > 1) { root = i; break; }
    vector<int> leaves;
    vector<pair<int,int>> st2;
    st2.push_back({root, 0});
    while (!st2.empty()) {
        auto [u, p] = st2.back(); st2.pop_back();
        bool leaf = true;
        for (int i = (int)g[u].size()-1; i >= 0; i--) {
            int v = g[u][i];
            if (v != p) { leaf = false; st2.push_back({v, u}); }
        }
        if (leaf) leaves.push_back(u);
    }
    int L = leaves.size();
    int k = (L + 1) / 2;
    cout << k << "\n";
    for (int i = 0; i < L/2; i++) cout << leaves[i] << " " << leaves[i + L/2] << "\n";
    if (L % 2) cout << leaves[L/2] << " " << leaves[L-1] << "\n";
    return 0;
}
