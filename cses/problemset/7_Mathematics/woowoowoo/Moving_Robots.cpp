#include <iostream>
#include <iomanip>
using namespace std;

int dirs(int x, int y) {
    int c = 0;
    if (x + 1 < 8) c++;
    if (y + 1 < 8) c++;
    if (x - 1 >= 0) c++;
    if (y - 1 >= 0) c++;
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double dp[64][64][101] = {0};
    for (int i = 0; i < 64; i++)
        dp[i][i][0] = 1;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        for (int x = 0; x < 64; x++) {
            for (int y = 0; y < 64; y++) {
                int a = x / 8, b = x % 8;
                long double p = 0;
                if (a + 1 < 8)
                    p += 1.0 / dirs(a + 1, b) * dp[a * 8 + 8 + b][y][i - 1];
                if (b + 1 < 8)
                    p += 1.0 / dirs(a, b + 1) * dp[a * 8 + b + 1][y][i - 1];
                if (a - 1 >= 0)
                    p += 1.0 / dirs(a - 1, b) * dp[a * 8 - 8 + b][y][i - 1];
                if (b - 1 >= 0)
                    p += 1.0 / dirs(a, b - 1) * dp[a * 8 + b - 1][y][i - 1];
                dp[x][y][i] = p;
            }
        }
    }
    long double ans = 0;
    for (int x = 0; x < 64; x++) {
        long double t = 1;
        for (int y = 0; y < 64; y++)
            t *= (1 - dp[x][y][k]);
        ans += t;
    }
    cout << setprecision(6) << fixed << ans << '\n';
    return 0;
}
