#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

struct Mat {
    ll a[6][6];
    Mat() { memset(a, 0, sizeof a); }
    Mat operator*(const Mat &o) const {
        Mat res;
        for (int i = 0; i < 6; i++)
            for (int k = 0; k < 6; k++)
                if (a[i][k])
                    for (int j = 0; j < 6; j++)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return res;
    }
};

Mat mat_pow(Mat m, ll e) {
    Mat res;
    for (int i = 0; i < 6; i++) res.a[i][i] = 1;
    while (e) {
        if (e & 1) res = res * m;
        m = m * m;
        e >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    if (n <= 6) {
        cout << (1LL << (n - 1)) % MOD << "\n";
        return 0;
    }
    Mat trans;
    for (int j = 0; j < 6; j++) trans.a[0][j] = 1;
    for (int i = 1; i < 6; i++) trans.a[i][i - 1] = 1;
    Mat res = mat_pow(trans, n - 6);
    ll ans = 0;
    for (int j = 0; j < 6; j++)
        ans = (ans + res.a[0][j] * (1LL << (5 - j)) % MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
