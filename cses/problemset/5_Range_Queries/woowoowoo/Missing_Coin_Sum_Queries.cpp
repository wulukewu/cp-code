#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxN = 200002;
const int logC = 32;
const int logN = 18;
const int INF = 0x3f3f3f3f;

int N, Q, mn[logC][logN][maxN];
ll pre[logC][maxN];

int layer(int x) {
    return 31 - __builtin_clz(x);
}

ll sum(int l, int a, int b) {
    return pre[l][b] - pre[l][a - 1];
}

int minimum(int l, int a, int b) {
    a--; b--;
    int len = b - a + 1;
    int k = (int)floor(log2(len));
    return min(mn[l][k][a], mn[l][k][b - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        int l = layer(x);
        pre[l][i] = x;
        for (int j = 0; j < logC; j++)
            mn[j][0][i - 1] = (j == l ? x : INF);
    }
    for (int l = 0; l < logC; l++) {
        for (int j = 1; j <= N; j++)
            pre[l][j] += pre[l][j - 1];
        for (int i = 1; i < logN; i++)
            for (int j = 0; j <= N - (1 << i); j++)
                mn[l][i][j] = min(mn[l][i - 1][j], mn[l][i - 1][j + (1 << (i - 1))]);
    }
    for (int q = 0, a, b; q < Q; q++) {
        cin >> a >> b;
        ll ans = 1;
        for (int l = 0; l < logC && ans >= (1LL << l); l++)
            if (minimum(l, a, b) <= ans)
                ans += sum(l, a, b);
        cout << ans << '\n';
    }
    return 0;
}
