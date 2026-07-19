#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) arr[i] = (1LL * a * arr[i - 1] + b) % c;
    int cur = 0, ans = 0;
    for (int i = 0; i < k; i++) cur ^= arr[i];
    ans ^= cur;
    for (int i = k; i < n; i++) {
        cur ^= arr[i] ^ arr[i - k];
        ans ^= cur;
    }
    cout << ans << "\n";
    return 0;
}
