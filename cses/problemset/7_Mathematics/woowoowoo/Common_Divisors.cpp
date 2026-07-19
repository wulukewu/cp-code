#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> freq(MAX + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for (int g = MAX; g >= 1; g--) {
        int cnt = 0;
        for (int m = g; m <= MAX; m += g)
            cnt += freq[m];
        if (cnt >= 2) {
            cout << g << "\n";
            return 0;
        }
    }
    return 0;
}
