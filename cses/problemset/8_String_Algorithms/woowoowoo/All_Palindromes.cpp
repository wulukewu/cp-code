#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1(n), d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++) {
        ans[i + d1[i] - 1] = max(ans[i + d1[i] - 1], d1[i] * 2 - 1);
        if (d2[i] > 0) ans[i + d2[i] - 1] = max(ans[i + d2[i] - 1], d2[i] * 2);
    }
    for (int i = n - 1; i > 0; i--) ans[i - 1] = max(ans[i - 1], ans[i] - 2);
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
