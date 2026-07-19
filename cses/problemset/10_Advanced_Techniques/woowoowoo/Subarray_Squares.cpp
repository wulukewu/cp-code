#include <bits/stdc++.h>
using namespace std;

long long cost(const vector<long long> &p, int i, int j) {
    long long sum = p[j + 1] - p[i];
    return sum * sum;
}

void divide(int l, int r, int optL, int optR, vector<long long> &dp,
            const vector<long long> &dpPrev, const vector<long long> &p) {
    if (l > r) return;
    int m = (l + r) / 2;
    int bestK = optL;
    for (int k = optL; k <= min(m, optR); k++) {
        long long cur = dpPrev[k] + cost(p, k, m - 1);
        if (cur < dp[m]) { dp[m] = cur; bestK = k; }
    }
    divide(l, m - 1, optL, bestK, dp, dpPrev, p);
    divide(m + 1, r, bestK, optR, dp, dpPrev, p);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<long long> a(n), p(n + 1);
    for (int i = 0; i < n; i++) { cin >> a[i]; p[i + 1] = p[i] + a[i]; }
    const long long INF = 1e18;
    vector<long long> dp(n + 1, INF), dpPrev(n + 1);
    dp[0] = 0;
    for (int j = 1; j <= k; j++) {
        dpPrev = dp;
        fill(dp.begin(), dp.end(), INF);
        divide(1, n, 0, n, dp, dpPrev, p);
    }
    cout << dp[n] << "\n";
    return 0;
}
