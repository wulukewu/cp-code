#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int xr = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i & 1) xr ^= a;
        }
        if (xr) cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}
