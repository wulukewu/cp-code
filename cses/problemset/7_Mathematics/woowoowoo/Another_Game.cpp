#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool odd = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x % 2 == 1) odd = true;
        }
        cout << (odd ? "first" : "second") << "\n";
    }
    return 0;
}
