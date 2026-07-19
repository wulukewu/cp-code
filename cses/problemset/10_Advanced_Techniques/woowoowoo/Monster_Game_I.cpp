#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<pair<int, long long>> S = {{k, 0}};
    vector<int> v = {1};
    int s[n], f[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> f[i];
    long long c = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i];
        int it = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        int m = f[i];
        c = 1LL * x * S[it].first + S[it].second;
        if (S.back().first == m) continue;
        while (S.size() >= 2) {
            auto y2 = S[S.size() - 1];
            auto y3 = S[S.size() - 2];
            if ((y2.second - c) * (m - y3.first) < (y3.second - c) * (m - y2.first)) {
                S.pop_back();
                v.pop_back();
            } else break;
        }
        int x1 = (int)ceil((S.back().second - c) * 1.0 / (m - S.back().first));
        v.push_back(x1);
        S.push_back({m, c});
    }
    cout << c << "
";
    return 0;
}
