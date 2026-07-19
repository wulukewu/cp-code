#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> tin(n+1, 0), low(n+1, 0);
    vector<bool> isArt(n+1, false);
    vector<int> artId(n+1, 0);
    vector<vector<int>> blocks;
    stack<pair<int,int>> edgeSt;
    int timer = 0, artCnt = 0;
    vector<int> compOf(n+1, 0);
    function<void(int,int)> dfs = [&](int u, int p) {
        tin[u] = low[u] = ++timer;
        int children = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            if (tin[v]) {
                if (tin[v] < tin[u]) edgeSt.push({u, v});
                low[u] = min(low[u], tin[v]);
            } else {
                edgeSt.push({u, v});
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    if (p != -1) isArt[u] = true;
                    blocks.push_back({});
                    while (true) {
                        auto e = edgeSt.top(); edgeSt.pop();
                        blocks.back().push_back(e.first);
                        blocks.back().push_back(e.second);
                        if (e.first == u && e.second == v) break;
                    }
                }
                children++;
            }
        }
        if (p == -1 && children > 1) isArt[u] = true;
    };
    for (int i = 1; i <= n; i++) if (!tin[i]) {
        dfs(i, -1);
        if (!edgeSt.empty()) {
            blocks.push_back({});
            while (!edgeSt.empty()) {
                auto e = edgeSt.top(); edgeSt.pop();
                blocks.back().push_back(e.first);
                blocks.back().push_back(e.second);
            }
        }
    }
    for (int u = 1; u <= n; u++) if (isArt[u]) artId[u] = ++artCnt;
    int total = artCnt + (int)blocks.size() + 1;
    vector<vector<int>> bcTree(total);
    auto addEdge = [&](int a, int b) {
        bcTree[a].push_back(b);
        bcTree[b].push_back(a);
    };
    for (int i = 0; i < (int)blocks.size(); i++) {
        int blockNode = artCnt + i + 1;
        for (int u : blocks[i]) {
            if (isArt[u]) {
                compOf[u] = artId[u];
                addEdge(artId[u], blockNode);
            } else {
                compOf[u] = blockNode;
            }
        }
    }
    int N = total;
    int LOG = 0;
    while ((1 << LOG) <= N) LOG++;
    vector<int> depth(N, 0), tinLCA(N, 0), toutLCA(N, 0);
    vector<vector<int>> up(N, vector<int>(LOG, 0));
    timer = 0;
    function<void(int,int)> dfsLCA = [&](int u, int p) {
        tinLCA[u] = ++timer;
        up[u][0] = p;
        for (int k = 1; k < LOG; k++) up[u][k] = up[up[u][k-1]][k-1];
        for (int v : bcTree[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfsLCA(v, u);
        }
        toutLCA[u] = ++timer;
    };
    for (int i = 1; i < N; i++) if (!tinLCA[i]) dfsLCA(i, 0);
    auto isAnc = [&](int a, int b) {
        return tinLCA[a] <= tinLCA[b] && toutLCA[a] >= toutLCA[b];
    };
    auto lca = [&](int a, int b) {
        if (isAnc(a, b)) return a;
        if (isAnc(b, a)) return b;
        for (int k = LOG-1; k >= 0; k--) if (!isAnc(up[a][k], b)) a = up[a][k];
        return up[a][0];
    };
    auto dist = [&](int a, int b) {
        return depth[a] + depth[b] - 2*depth[lca(a, b)];
    };
    for (int i = 0; i < q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == c || b == c) {
            cout << "NO\n";
            continue;
        }
        if (!isArt[c]) {
            cout << "YES\n";
            continue;
        }
        int na = compOf[a], nb = compOf[b], nc = artId[c];
        if (dist(na, nc) + dist(nc, nb) == dist(na, nb)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
