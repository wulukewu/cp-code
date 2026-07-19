#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long cur = 0, ans = -1e18;
    for (int i = 0; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
