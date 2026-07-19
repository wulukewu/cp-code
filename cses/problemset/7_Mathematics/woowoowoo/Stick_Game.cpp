#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    vector<bool> win(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= p[j] && !win[i - p[j]]) {
                win[i] = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (win[i] ? 'W' : 'L');
    cout << "\n";
    return 0;
}
