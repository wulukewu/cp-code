#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
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
    string s;
    cin >> s;
    vector<int> pi = prefix_function(s);
    int n = s.size();
    vector<int> borders;
    int len = pi[n - 1];
    while (len > 0) {
        borders.push_back(len);
        len = pi[len - 1];
    }
    sort(borders.begin(), borders.end());
    for (int x : borders) cout << x << ' ';
    cout << '\n';
    return 0;
}
