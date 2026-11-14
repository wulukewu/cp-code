/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc481_g // Half-Baked
 https://atcoder.jp/contests/abc481/tasks/abc481_g

 AC // C++23 (GCC 15.2.0) // 298 ms // 600.0 pt
 #80349798 // 2026-10-24 21:40:28 +0800
 https://atcoder.jp/contests/abc481/submissions/80349798

 cp-code:submission-metadata
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int POW(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a % MOD;
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<int> fac, ifac, pw2;

void NTT(vector<int>& a, bool inv) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = POW(3, (MOD - 1) / len);
        if (inv) wlen = POW(wlen, MOD - 2);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (ll)a[i + j + len / 2] * w % MOD;

                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;

                w = (ll)w * wlen % MOD;
            }
        }
    }

    if (inv) {
        int x = POW(n, MOD - 2);
        for (int &v : a) v = (ll)v * x % MOD;
    }
}

// Multiply polynomial p by (1+x)^d
vector<int> multiply(vector<int> p, int d) {
    if (d == 0) return p;

    int m = p.size();
    vector<int> b(d + 1);

    for (int i = 0; i <= d; i++) {
        b[i] = (ll)fac[d] * ifac[i] % MOD
             * ifac[d - i] % MOD;
    }

    if ((ll)m * (d + 1) <= 5000) {
        vector<int> res(m + d);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= d; j++) {
                res[i + j] = (res[i + j]
                    + (ll)p[i] * b[j]) % MOD;
            }
        }
        return res;
    }

    int sz = 1;
    while (sz < m + d) sz <<= 1;

    p.resize(sz);
    b.resize(sz);

    NTT(p, false);
    NTT(b, false);

    for (int i = 0; i < sz; i++) {
        p[i] = (ll)p[i] * b[i] % MOD;
    }

    NTT(p, true);
    p.resize(m + d);

    return p;
}

struct Event {
    int a, b, c;
};

struct Node {
    int a, b;
    vector<int> p;
};

vector<Event> ev;

Node DC(int l, int r) {
    if (r - l == 1) {
        return {ev[l].a, ev[l].b, {ev[l].c}};
    }

    int m = (l + r) / 2;

    Node L = DC(l, m);
    Node R = DC(m, r);

    int b = min(L.b, R.b);
    int shift = R.a - L.a;

    if (L.b > b) {
        L.p = multiply(move(L.p), L.b - b);
    }

    if (R.b > b) {
        R.p = multiply(move(R.p), R.b - b);
    }

    int sz = max((int)L.p.size(),
                 (int)R.p.size() + shift);

    L.p.resize(sz);

    for (int i = 0; i < (int)R.p.size(); i++) {
        int &x = L.p[i + shift];
        x += R.p[i];
        if (x >= MOD) x -= MOD;
    }

    return {L.a, b, move(L.p)};
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v.emplace_back(a, 0);
        v.emplace_back(b, 1);
    }

    sort(v.begin(), v.end());

    fac.resize(n + 1);
    ifac.resize(n + 1);
    pw2.resize(n + 1);

    fac[0] = ifac[0] = pw2[0] = 1;

    for (int i = 1; i <= n; i++) {
        fac[i] = (ll)fac[i - 1] * i % MOD;
        pw2[i] = (ll)pw2[i - 1] * 2 % MOD;
    }

    ifac[n] = POW(fac[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        ifac[i - 1] = (ll)ifac[i] * i % MOD;
    }

    int done = 0, active = 0;

    for (auto [x, t] : v) {
        int a = done;
        int b = active - (t == 1);

        int c = (ll)x * pw2[n - 1 - b] % MOD;

        ev.push_back({a, b, c});

        if (t == 0) {
            active++;
        } else {
            active--;
            done++;
        }
    }

    Node ans = DC(0, 2 * n);

    ans.p.resize(n);

    for (int x : ans.p) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
