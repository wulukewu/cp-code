#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mxN = 200005;
int par[mxN], len[mxN];

void init() {
    for (int i = 0; i < mxN; i++) par[i] = i, len[i] = 1;
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void join(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) {
        if (len[x] < len[y]) swap(x, y);
        par[y] = x; len[x] += len[y];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t; cin >> n >> m >> t;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;
    vector<pair<int,int>> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i].first >> queries[i].second;
    vector<pair<int,int>> range(t, {0, m});
    vector<int> ans(t, -1);
    while (true) {
        init();
        vector<pair<int,int>> mid;
        for (int i = 0; i < t; i++)
            if (range[i].first <= range[i].second) {
                int ml = (range[i].first + range[i].second) / 2;
                mid.push_back({ml, i});
            }
        if (mid.empty()) break;
        sort(mid.begin(), mid.end());
        int j = 0;
        for (int i = 0; i <= m; i++) {
            if (i) join(edges[i-1].first, edges[i-1].second);
            while (j < (int)mid.size() && mid[j].first == i) {
                int k = mid[j].second;
                if (find(queries[k].first) == find(queries[k].second)) {
                    ans[k] = i;
                    range[k] = {range[k].first, i - 1};
                } else {
                    range[k] = {i + 1, range[k].second};
                }
                j++;
            }
        }
    }
    for (int i = 0; i < t; i++) cout << ans[i] << "\n";
    return 0;
}
