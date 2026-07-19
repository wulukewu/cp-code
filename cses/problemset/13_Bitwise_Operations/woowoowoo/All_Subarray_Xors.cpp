#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void fwht(vector<ll>& a, bool invert) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = a[i + j];
                ll v = a[i + j + len];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int N = 1 << 20;
    int n;
    cin >> n;
    vector<ll> a(N, 0);
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) v[i] ^= v[i - 1];
    a[0]++;
    for (int i = 0; i < n; i++) a[v[i]]++;
    fwht(a, false);
    for (int i = 0; i < N; i++) a[i] = a[i] * a[i];
    fwht(a, true);
    vector<int> res;
    for (int i = 0; i < N; i++)
        if (a[i] > 0) {
            if (i == 0 && a[i] == n + 1) continue;
            res.push_back(i);
        }
    cout << res.size() << '\n';
    for (int x : res) cout << x << " ";
    cout << '\n';
    return 0;
}
