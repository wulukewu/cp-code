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
    long long sum_low = 0, sum_high = 0;

    auto balance = [&]() {
        while (low.size() < high.size()) {
            int x = *high.begin();
            sum_low += x;
            sum_high -= x;
            low.insert(x);
            high.erase(high.begin());
        }
        while (low.size() > high.size() + 1) {
            int x = *low.rbegin();
            sum_high += x;
            sum_low -= x;
            high.insert(x);
            low.erase(prev(low.end()));
        }
    };

    for (int i = 0; i < n; i++) {
        if (low.empty() || a[i] <= *low.rbegin()) {
            low.insert(a[i]);
            sum_low += a[i];
        } else {
            high.insert(a[i]);
            sum_high += a[i];
        }
        balance();

        if (i >= k) {
            int out = a[i - k];
            auto it = low.find(out);
            if (it != low.end()) {
                low.erase(it);
                sum_low -= out;
            } else {
                high.erase(high.find(out));
                sum_high -= out;
            }
            balance();
        }

        if (i >= k - 1) {
            long long med = *low.rbegin();
            long long cost = med * low.size() - sum_low + sum_high - med * high.size();
            cout << cost << (i + 1 < n ? " " : "\n");
        }
    }

    return 0;
}
