#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int med = p[n / 2];
    long long ans = 0;
    for (int x : p) ans += abs(x - med);
    cout << ans << '\n';
    return 0;
}
