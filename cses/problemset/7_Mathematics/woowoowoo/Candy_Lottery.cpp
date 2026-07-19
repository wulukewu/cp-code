#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    int n, k;
    cin >> n >> k;
    double ans = k;
    for (int m = 1; m < k; m++)
        ans -= pow((double)m / k, n);
    cout << ans << "\n";
    return 0;
}
