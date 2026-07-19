#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    vector<long long> cnt(n, 0);
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int mod = ((pref[i] % n) + n) % n;
        ans += cnt[mod];
        cnt[mod]++;
    }
    cout << ans << '\n';
    return 0;
}
