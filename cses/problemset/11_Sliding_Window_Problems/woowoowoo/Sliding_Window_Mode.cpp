#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> freq;
    set<pair<int, int>> freq_set;
    auto add = [&](int v) {
        int f = freq[v];
        if (f > 0) freq_set.erase({f, -v});
        freq[v] = f + 1;
        freq_set.insert({f + 1, -v});
    };
    auto remove = [&](int v) {
        int f = freq[v];
        freq_set.erase({f, -v});
        if (f > 1) freq_set.insert({f - 1, -v});
        freq[v] = f - 1;
    };
    for (int i = 0; i < k; i++) add(a[i]);
    cout << -(prev(freq_set.end())->second);
    for (int i = k; i < n; i++) {
        remove(a[i - k]);
        add(a[i]);
        cout << " " << -(prev(freq_set.end())->second);
    }
    cout << "\n";
    return 0;
}
