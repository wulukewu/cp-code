#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    k = n - k;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) cin >> dp[i];
    for (int i = 0; i < 20; i++)
        if (k >> i & 1)
            for (int j = 0; j < n - (1 << i); j++)
                dp[j] ^= dp[j + (1 << i)];
    for (int i = 0; i < n - k; i++) cout << dp[i] << " ";
    cout << '\n';
    return 0;
}
