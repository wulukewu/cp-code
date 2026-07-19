#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    struct Range { int l, r, idx; };
    vector<Range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }
    sort(a.begin(), a.end(), [](Range &x, Range &y) {
        if (x.l != y.l) return x.l < y.l;
        return x.r > y.r;
    });
    vector<int> contains(n, 0), contained(n, 0);
    int max_r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].r <= max_r) contained[a[i].idx] = 1;
        max_r = max(max_r, a[i].r);
    }
    int min_r = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].r >= min_r) contains[a[i].idx] = 1;
        min_r = min(min_r, a[i].r);
    }
    for (int i = 0; i < n; i++) cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << contained[i] << ' ';
    cout << '\n';
    return 0;
}
