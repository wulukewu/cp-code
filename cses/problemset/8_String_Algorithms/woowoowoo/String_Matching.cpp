#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t, p;
    cin >> t >> p;
    string s = p + '#' + t;
    vector<int> pi = kmp(s);
    int m = p.size(), ans = 0;
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) ans++;
    }
    cout << ans << '\n';
    return 0;
}
