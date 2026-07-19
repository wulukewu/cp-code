#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : abs(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll area2 = 0, B = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area2 += x[i] * y[j] - x[j] * y[i];
        B += gcd(x[j] - x[i], y[j] - y[i]);
    }
    area2 = abs(area2);
    ll I = (area2 - B) / 2 + 1;
    cout << I << ' ' << B << '\n';
    return 0;
}
