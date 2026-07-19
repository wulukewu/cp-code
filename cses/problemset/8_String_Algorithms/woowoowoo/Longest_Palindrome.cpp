#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    int m = t.size();
    vector<int> p(m, 0);
    int c = 0, r = 0;
    for (int i = 0; i < m; i++) {
        int mir = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mir]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    int maxLen = 0, center = 0;
    for (int i = 0; i < m; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }
    int start = (center - maxLen) / 2;
    cout << s.substr(start, maxLen) << '\n';
    return 0;
}
