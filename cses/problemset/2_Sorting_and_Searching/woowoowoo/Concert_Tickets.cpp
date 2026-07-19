#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x;
    cin >> n >> m;
    multiset<int> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.insert(x);
    }
    while (m--) {
        cin >> x;
        auto it = t.upper_bound(x);
        if (it == t.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            t.erase(it);
        }
    }
    return 0;
}
