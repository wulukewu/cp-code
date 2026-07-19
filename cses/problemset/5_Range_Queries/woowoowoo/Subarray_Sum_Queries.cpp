#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE = 800000;

int N, Q, k, lo[SIZE], hi[SIZE], mp[SIZE];
ll x, sum[SIZE], dp[SIZE], dpl[SIZE], dpr[SIZE];

void pull(int i) {
    dpl[i] = max(dpl[2 * i], sum[2 * i] + dpl[2 * i + 1]);
    dpr[i] = max(dpr[2 * i + 1], sum[2 * i + 1] + dpr[2 * i]);
    dp[i] = max(dpr[2 * i] + dpl[2 * i + 1], max(dp[2 * i], dp[2 * i + 1]));
    sum[i] = sum[2 * i] + sum[2 * i + 1];
}

void build(int i, int l, int r) {
    lo[i] = l; hi[i] = r;
    if (l == r) {
        cin >> sum[i];
        dpl[i] = dpr[i] = dp[i] = sum[i];
        mp[l] = i;
        return;
    }
    int m = l + (r - l) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    pull(i);
}

void update(int a, ll b) {
    a = mp[a];
    dpl[a] = dpr[a] = dp[a] = sum[a] = b;
    a >>= 1;
    while (a > 0) {
        pull(a);
        a >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    build(1, 1, N);
    for (int q = 0; q < Q; q++) {
        cin >> k >> x;
        update(k, x);
        cout << max(0LL, dp[1]) << '\n';
    }
    return 0;
}
