#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = 1;
        int ni = i, ki = n - 1;
        if (ki < ni - ki) ki = ni - ki;
        for (int j = ki + 1; j <= ni; j++) {
            int x = j;
            while (x % 2 == 0) { c ^= 1; x /= 2; }
        }
        for (int j = 1; j <= ni - ki; j++) {
            int x = j;
            while (x % 2 == 0) { c ^= 1; x /= 2; }
        }
        if (c) ans ^= a[i];
    }

    cout << ans << "\n";
    return 0;
}
