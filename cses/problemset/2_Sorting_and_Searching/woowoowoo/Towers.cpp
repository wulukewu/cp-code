#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    multiset<int> tops;
    while (n--) {
        cin >> x;
        auto it = tops.upper_bound(x);
        if (it != tops.end()) tops.erase(it);
        tops.insert(x);
    }
    cout << tops.size() << '\n';
    return 0;
}
