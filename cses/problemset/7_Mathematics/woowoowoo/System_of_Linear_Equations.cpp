#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long modpow(long long n, long long k) {
    long long ans = 1 % MOD;
    n %= MOD;
    if (n < 0) n += MOD;
    while (k) {
        if (k & 1) ans = ans * n % MOD;
        n = n * n % MOD;
        k >>= 1;
    }
    return ans;
}

int Gauss(vector<vector<int>> a, vector<int> &ans) {
    int n = a.size(), m = a[0].size() - 1;
    vector<int> pos(m, -1);
    const long long MODSQ = (long long)MOD * MOD;
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int mx = row;
        for (int k = row; k < n; k++)
            if (a[k][col] > a[mx][col]) mx = k;
        if (a[mx][col] == 0) continue;
        for (int j = col; j <= m; j++) swap(a[mx][j], a[row][j]);
        pos[col] = row;
        int inv = modpow(a[row][col], MOD - 2);
        for (int i = 0; i < n && inv; i++) {
            if (i != row && a[i][col]) {
                int x = (long long)a[i][col] * inv % MOD;
                for (int j = col; j <= m && x; j++) {
                    if (a[row][j])
                        a[i][j] = (MODSQ + a[i][j] - (long long)a[row][j] * x) % MOD;
                }
            }
        }
        row++;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; i++) {
        if (pos[i] != -1)
            ans[i] = (long long)a[pos[i]][m] * modpow(a[pos[i]][i], MOD - 2) % MOD;
    }
    for (int i = 0; i < n; i++) {
        long long val = 0;
        for (int j = 0; j < m; j++)
            val = (val + (long long)ans[j] * a[i][j]) % MOD;
        if (val != a[i][m]) return -1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            cin >> A[i][j];
    vector<int> ans;
    if (Gauss(A, ans) == -1) {
        cout << -1 << '\n';
    } else {
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
