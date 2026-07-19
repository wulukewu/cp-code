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
    vector<int> cnt(31, 0);
    int cur = 0, ans = 0;
    auto add = [&](int v) {
        for (int b = 0; b < 31; b++) {
            if (v & (1 << b)) {
                if (cnt[b] == 0) cur |= (1 << b);
                cnt[b]++;
            }
        }
    };
    auto remove = [&](int v) {
        for (int b = 0; b < 31; b++) {
            if (v & (1 << b)) {
                cnt[b]--;
                if (cnt[b] == 0) cur &= ~(1 << b);
            }
        }
    };
    for (int i = 0; i < k; i++) add(arr[i]);
    ans ^= cur;
    for (int i = k; i < n; i++) {
        remove(arr[i - k]);
        add(arr[i]);
        ans ^= cur;
    }
    cout << ans << "\n";
    return 0;
}
