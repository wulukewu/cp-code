#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].second >> m[i].first;
    }
    sort(m.begin(), m.end());
    int ans = 0, end = 0;
    for (auto &p : m) {
        if (p.second >= end) {
            ans++;
            end = p.first;
        }
    }
    cout << ans << '\n';
    return 0;
}
