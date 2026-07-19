#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll sum = 0, sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * i - sx + y[i] * i - sy;
        sx += x[i];
        sy += y[i];
    }
    cout << sum << "\n";
    return 0;
}
