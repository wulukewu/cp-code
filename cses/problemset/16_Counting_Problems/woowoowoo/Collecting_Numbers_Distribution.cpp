#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 5005;

ll A[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    A[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            A[i][k] = (k * A[i-1][k] + (i - k + 1) * A[i-1][k-1]) % MOD;
        }
    }
    for (int k = 1; k <= n; k++) cout << A[n][k] % MOD << "\n";
    return 0;
}
