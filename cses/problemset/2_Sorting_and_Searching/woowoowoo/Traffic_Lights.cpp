#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;
    set<int> pos = {0, x};
    multiset<int> gaps = {x};
    while (n--) {
        int p;
        cin >> p;
        auto it = pos.upper_bound(p);
        int r = *it;
        int l = *prev(it);
        gaps.erase(gaps.find(r - l));
        gaps.insert(p - l);
        gaps.insert(r - p);
        pos.insert(p);
        cout << *gaps.rbegin() << ' ';
    }
    cout << '\n';
    return 0;
}
