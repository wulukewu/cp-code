#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    auto it = s.begin();
    while (!s.empty()) {
        if (it == s.end()) it = s.begin();
        ++it;
        if (it == s.end()) it = s.begin();
        cout << *it << ' ';
        it = s.erase(it);
    }
    cout << '\n';
    return 0;
}
