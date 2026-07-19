#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int leftN = n / 2, rightN = n - leftN;
    vector<long long> leftSums, rightSums;
    for (int mask = 0; mask < (1 << leftN); mask++) {
        long long sum = 0;
        for (int i = 0; i < leftN; i++)
            if (mask & (1 << i)) sum += a[i];
        leftSums.push_back(sum);
    }
    for (int mask = 0; mask < (1 << rightN); mask++) {
        long long sum = 0;
        for (int i = 0; i < rightN; i++)
            if (mask & (1 << i)) sum += a[leftN + i];
        rightSums.push_back(sum);
    }
    sort(rightSums.begin(), rightSums.end());
    long long ans = 0;
    for (auto v : leftSums) {
        auto lo = lower_bound(rightSums.begin(), rightSums.end(), x - v);
        auto hi = upper_bound(rightSums.begin(), rightSums.end(), x - v);
        ans += hi - lo;
    }
    cout << ans << "\n";
    return 0;
}
