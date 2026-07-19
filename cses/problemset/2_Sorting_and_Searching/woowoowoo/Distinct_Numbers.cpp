#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) ans++;
    }
    cout << ans << '\n';
    return 0;
}
