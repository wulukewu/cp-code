#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> basis(60);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        for (int b = 59; b >= 0; b--) {
            if ((x >> b) & 1) {
                if (basis[b]) x ^= basis[b];
                else { basis[b] = x; break; }
            }
        }
    }

    long long ans = 0;
    for (int b = 59; b >= 0; b--) {
        if ((ans ^ basis[b]) > ans) ans ^= basis[b];
    }

    cout << ans << "\n";
    return 0;
}
