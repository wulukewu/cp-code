#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> radj(n + 1);
    vector<int> outdeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        radj[b].push_back(a);
        outdeg[a]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == 0) pq.push(i);
    }
    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (int v : radj[u]) {
            outdeg[v]--;
            if (outdeg[v] == 0) pq.push(v);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
