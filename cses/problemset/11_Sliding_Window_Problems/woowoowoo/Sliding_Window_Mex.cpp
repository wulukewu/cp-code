#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> freq(n + 2);
    set<int> missing;
    for (int i = 0; i <= n; i++) missing.insert(i);
    for (int i = 0; i < k; i++) {
        if (freq[a[i]]++ == 0) missing.erase(a[i]);
    }
    cout << *missing.begin();
    for (int i = k; i < n; i++) {
        int out = a[i - k], in = a[i];
        if (--freq[out] == 0) missing.insert(out);
        if (freq[in]++ == 0) missing.erase(in);
        cout << " " << *missing.begin();
    }
    cout << "\n";
    return 0;
}
