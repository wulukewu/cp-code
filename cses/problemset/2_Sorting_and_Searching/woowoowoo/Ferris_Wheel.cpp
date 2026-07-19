#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) {
            i++; j--;
        } else {
            j--;
        }
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
