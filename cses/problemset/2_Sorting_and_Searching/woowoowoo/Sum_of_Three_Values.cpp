#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int s = a[i].first + a[l].first + a[r].first;
            if (s == x) {
                cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
                return 0;
            } else if (s < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
