#include <iostream>
#include <vector>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 2) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    BIT bit(n);
    long long inv = 0;
    for (int i = 0; i < k; i++) {
        inv += bit.sum(n) - bit.sum(a[i]);
        bit.add(a[i], 1);
    }
    cout << inv;
    for (int i = k; i < n; i++) {
        bit.add(a[i - k], -1);
        inv -= bit.sum(a[i - k] - 1);
        inv += bit.sum(n) - bit.sum(a[i]);
        bit.add(a[i], 1);
        cout << " " << inv;
    }
    cout << "\n";
    return 0;
}
