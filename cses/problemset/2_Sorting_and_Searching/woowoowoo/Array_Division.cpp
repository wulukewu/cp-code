#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(lo, (long long)a[i]);
        hi += a[i];
    }
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        int cur = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                cur++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }
        if (sum > 0) cur++;
        if (cur <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}
