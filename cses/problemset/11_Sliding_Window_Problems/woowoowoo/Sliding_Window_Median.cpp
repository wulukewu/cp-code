#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> low, high;

    auto balance = [&]() {
        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        while (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
    };

    for (int i = 0; i < n; i++) {
        if (low.empty() || a[i] <= *low.rbegin()) low.insert(a[i]);
        else high.insert(a[i]);
        balance();

        if (i >= k) {
            int out = a[i - k];
            auto it = low.find(out);
            if (it != low.end()) low.erase(it);
            else high.erase(high.find(out));
            balance();
        }

        if (i >= k - 1) {
            cout << *low.rbegin() << (i + 1 < n ? " " : "\n");
        }
    }

    return 0;
}
