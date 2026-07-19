#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    double dp[605][105] = {0};
    dp[0][0] = 1.0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < 601; i++) {
            for (int k = 1; k <= 6; k++) {
                if (i - k >= 0)
                    dp[i][j] += dp[i - k][j - 1] * (1.0 / 6);
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; i++)
        ans += dp[i][n];
    cout << setprecision(6) << fixed << ans << '\n';
    return 0;
}
