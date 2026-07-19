#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
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
    int w, n, m; cin >> w >> n >> m;
    vector<int> a(w + 1, 0), b(w + 1, 0);
    for (int i = 0; i < n; i++) { int x; cin >> x; a[x]++; }
    for (int i = 0; i < m; i++) { int x; cin >> x; b[x]++; }
    int sz = 1;
    while (sz < (int)a.size() + (int)b.size() - 1) sz <<= 1;
    vector<base> fa(sz), fb(sz);
    for (int i = 0; i < (int)a.size(); i++) fa[i] = base(a[i], 0);
    for (int i = 0; i < (int)b.size(); i++) fb[i] = base(b[i], 0);
    fft(fa, 0); fft(fb, 0);
    for (int i = 0; i < sz; i++) fa[i] *= fb[i];
    fft(fa, 1);
    for (int i = 2; i <= 2 * w; i++) {
        long long val = (long long)(fa[i].real() + 0.5);
        cout << val << (i == 2 * w ? "\n" : " ");
    }
    return 0;
}
