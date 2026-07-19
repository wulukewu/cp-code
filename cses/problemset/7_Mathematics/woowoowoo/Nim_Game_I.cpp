#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int xr = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            xr ^= x;
        }
        cout << (xr ? "first" : "second") << "\n";
    }
    return 0;
}
