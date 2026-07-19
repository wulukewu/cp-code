#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void forward1(vector<int> &dp, int BITS) {
    for (int i = 0; i < BITS; i++)
        for (int j = 1; j < (int)dp.size(); j++)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
}

void forward2(vector<int> &dp, int BITS) {
    for (int i = 0; i < BITS; i++)
        for (int j = 1; j < (int)dp.size(); j++)
            if (j & (1 << i))
                dp[j ^ (1 << i)] += dp[j];
}

void backword1(vector<int> &dp, int BITS) {
    for (int i = 0; i < BITS; i++)
        for (int j = dp.size() - 1; j > 0; j--)
            if (j & (1 << i))
                dp[j] -= dp[j ^ (1 << i)];
}

void backword2(vector<int> &dp, int BITS) {
    for (int i = 0; i < BITS; i++)
        for (int j = dp.size() - 1; j > 0; j--)
            if (j & (1 << i))
                dp[j ^ (1 << i)] -= dp[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int N = 1 << 20;
    vector<int> a(N, 0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[v[i]]++;
    }
    forward1(a, 20);
    auto r1 = a;
    backword1(a, 20);
    forward2(a, 20);
    auto r2 = a;
    backword2(a, 20);
    for (int x : v) {
        int z = r1[(N - 1) ^ x];
        cout << r1[x] << " " << r2[x] << " " << n - z << '\n';
    }
    return 0;
}
