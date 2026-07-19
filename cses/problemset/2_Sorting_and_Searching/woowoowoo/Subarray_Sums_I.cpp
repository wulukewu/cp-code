#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    unordered_map<long long, int> cnt;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += cnt[pref[i] - x];
        cnt[pref[i]]++;
    }
    cout << ans << '\n';
    return 0;
}
