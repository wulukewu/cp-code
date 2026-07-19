#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 911382323;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<ll> pow1(n + 1), pow2(n + 1);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow1[i] = pow1[i - 1] * BASE % MOD1;
        pow2[i] = pow2[i - 1] * BASE % MOD2;
    }
    vector<ll> pref1(n + 1), pref2(n + 1);
    vector<ll> suf1(n + 2), suf2(n + 2);
    for (int i = 1; i <= n; i++) {
        int v = s[i - 1] - 'a' + 1;
        pref1[i] = (pref1[i - 1] * BASE + v) % MOD1;
        pref2[i] = (pref2[i - 1] * BASE + v) % MOD2;
    }
    for (int i = n; i >= 1; i--) {
        int v = s[i - 1] - 'a' + 1;
        suf1[i] = (suf1[i + 1] * BASE + v) % MOD1;
        suf2[i] = (suf2[i + 1] * BASE + v) % MOD2;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            char x;
            cin >> k >> x;
            int v = x - 'a' + 1;
            s[k - 1] = x;
            for (int i = k; i <= n; i++) {
                pref1[i] = (pref1[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD1;
                pref2[i] = (pref2[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD2;
            }
            for (int i = k; i >= 1; i--) {
                suf1[i] = (suf1[i + 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD1;
                suf2[i] = (suf2[i + 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD2;
            }
        } else {
            int l, r;
            cin >> l >> r;
            ll f1 = (pref1[r] - pref1[l - 1] * pow1[r - l + 1] % MOD1 + MOD1) % MOD1;
            ll f2 = (pref2[r] - pref2[l - 1] * pow2[r - l + 1] % MOD2 + MOD2) % MOD2;
            ll b1 = (suf1[l] - suf1[r + 1] * pow1[r - l + 1] % MOD1 + MOD1) % MOD1;
            ll b2 = (suf2[l] - suf2[r + 1] * pow2[r - l + 1] % MOD2 + MOD2) % MOD2;
            cout << (f1 == b1 && f2 == b2 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
