#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        inv[p[i]] = i;
    }
    char c = 'a';
    string s(n, ' ');
    s[p[0]] = 'a';
    for (int i = 1; i < n; i++) {
        if (p[i] == n - 1) {
            c++;
        } else if (p[i - 1] + 1 < n && inv[p[i - 1] + 1] > inv[p[i] + 1]) {
            c++;
        }
        if (c > 'z') {
            cout << -1 << '\n';
            return 0;
        }
        s[p[i]] = c;
    }
    cout << s << '\n';
    return 0;
}
