#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) cin >> dp[i];
    for (int i = 0; i < 20; i++)
        for (int j = 1; j < (int)dp.size(); j++)
            if (j & (1 << i))
                dp[j] ^= dp[j ^ (1 << i)];
    for (int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << '\n';
    return 0;
}
