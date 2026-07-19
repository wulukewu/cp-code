#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

struct Mat {
    ll a[2][2];
    Mat() { memset(a, 0, sizeof a); }
    Mat operator*(const Mat &o) const {
        Mat res;
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++)
                if (a[i][k])
                    for (int j = 0; j < 2; j++)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return res;
    }
};

Mat mat_pow(Mat m, ll e) {
    Mat res;
    res.a[0][0] = res.a[1][1] = 1;
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
    if (n == 0) { cout << "0\n"; return 0; }
    Mat base;
    base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    Mat res = mat_pow(base, n - 1);
    cout << res.a[0][0] << "\n";
    return 0;
}
