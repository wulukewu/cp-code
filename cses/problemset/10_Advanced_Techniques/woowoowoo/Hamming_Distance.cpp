#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < k; j++)
            if (s[j] == '1') v[i] += (1 << j);
    }
    int ans = k;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min(ans, __builtin_popcount(v[i] ^ v[j]));
    cout << ans << "
";
    return 0;
}
