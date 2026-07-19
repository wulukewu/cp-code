#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> div_cnt(MAX + 1);
    for (int i = 1; i <= MAX; i++)
        for (int j = i; j <= MAX; j += i)
            div_cnt[j]++;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        cout << div_cnt[x] << "\n";
    }
    return 0;
}
