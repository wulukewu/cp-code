#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    long long lo = 1, hi = 1e18;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        long long total = 0;
        for (int x : t) {
            total += mid / x;
            if (total >= k) break;
        }
        if (total >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}
