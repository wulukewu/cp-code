#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> t(n);
    long long sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
        mx = max(mx, t[i]);
    }
    cout << max(sum, 2LL * mx) << '\n';
    return 0;
}
