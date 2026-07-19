#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {s[i], i};
    sort(v.begin(), v.end());
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            pos = i;
            break;
        }
    }
    string ans;
    int cur = pos;
    for (int i = 0; i < n - 1; i++) {
        cur = v[cur].second;
        ans += s[cur];
    }
    cout << ans << '\n';
    return 0;
}
