#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

struct Mat {
    vector<vector<ll>> a;
    Mat(int n) : a(n, vector<ll>(n, 0)) {}
    Mat operator*(const Mat &o) const {
        int n = a.size();
        Mat res(n);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (a[i][k])
                    for (int j = 0; j < n; j++)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return res;
    }
};

Mat mat_pow(Mat m, ll e) {
    int n = m.a.size();
    Mat res(n);
    for (int i = 0; i < n; i++) res.a[i][i] = 1;
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
    int n, m; ll k;
    cin >> n >> m >> k;
    Mat adj(n);
    while (m--) {
        int a, b; cin >> a >> b;
        adj.a[a - 1][b - 1]++;
    }
    Mat res = mat_pow(adj, k);
    cout << res.a[0][n - 1] << "\n";
    return 0;
}
