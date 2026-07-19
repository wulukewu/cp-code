#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int logN = 17;
const int maxT = 1000000;

int dp[maxT + 1][logN + 1];
vector<int> movies[maxT + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        movies[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> ends;
    for (int t = maxT; t >= 0; t--) {
        for (int b : movies[t]) ends.push(b);
        dp[t][0] = ends.empty() ? maxT + 1 : ends.top();
    }
    for (int k = 1; k <= logN; k++)
        for (int t = 0; t <= maxT; t++)
            dp[t][k] = dp[t][k - 1] > maxT ? maxT + 1 : dp[dp[t][k - 1]][k - 1];
    for (int q = 0, a, b; q < Q; q++) {
        cin >> a >> b;
        int ans = 0;
        for (int k = logN; k >= 0; k--) {
            if (dp[a][k] <= b) {
                a = dp[a][k];
                ans += (1 << k);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
