#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const double PI = acos(-1);
typedef complex<double> base;

void fft(vector<base> &p, bool inv = 0) {
    int n = p.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(p[i], p[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? 1 : -1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = p[i + j], v = p[i + j + len / 2] * w;
                p[i + j] = u + v;
                p[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) for (int i = 0; i < n; i++) p[i] /= n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    vector<base> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i] = base(1, 0);
            b[n - i - 1] = base(1, 0);
        }
    }
    int sz = 1;
    while (sz < 2 * n - 1) sz <<= 1;
    a.resize(sz); b.resize(sz);
    fft(a, 0); fft(b, 0);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    fft(a, 1);
    for (int i = n; i < 2 * n - 1; i++)
        cout << (long long)(a[i].real() + 0.5) << (i == 2 * n - 2 ? "\n" : " ");
    return 0;
}
