#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> dp = {0, 0, 0};
    for (int i = 3; i < 2000; i++) {
        set<int> s;
        for (int j = 1; i - j > j; j++)
            s.insert(dp[j] ^ dp[i - j]);
        int g = 0;
        while (s.count(g)) g++;
        dp.push_back(g);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n >= 2000) cout << "first\n";
        else cout << (dp[n] > 0 ? "first\n" : "second\n");
    }
    return 0;
}
