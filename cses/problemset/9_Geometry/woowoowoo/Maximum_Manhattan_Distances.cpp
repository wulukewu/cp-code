#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ll mn1 = LLONG_MAX, mx1 = LLONG_MIN;
    ll mn2 = LLONG_MAX, mx2 = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        ll v1 = x + y;
        ll v2 = x - y;
        if (v1 < mn1) mn1 = v1;
        if (v1 > mx1) mx1 = v1;
        if (v2 < mn2) mn2 = v2;
        if (v2 > mx2) mx2 = v2;
        cout << max(mx1 - mn1, mx2 - mn2) << "\n";
    }
    return 0;
}
