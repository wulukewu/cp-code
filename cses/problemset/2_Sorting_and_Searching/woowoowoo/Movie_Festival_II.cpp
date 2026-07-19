#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].second >> m[i].first;
    }
    sort(m.begin(), m.end());
    multiset<int> ends;
    for (int i = 0; i < k; i++) ends.insert(0);
    int ans = 0;
    for (auto &p : m) {
        auto it = ends.upper_bound(p.second);
        if (it == ends.begin()) continue;
        --it;
        ends.erase(it);
        ends.insert(p.first);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
