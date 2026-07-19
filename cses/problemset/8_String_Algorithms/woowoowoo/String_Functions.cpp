#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n), z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j++;
        pi[i] = j;
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << z[i];
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << pi[i];
    }
    cout << '\n';
    return 0;
}
