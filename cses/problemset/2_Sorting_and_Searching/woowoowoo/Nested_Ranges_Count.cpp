#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    struct Range { int l, r, idx; };
    vector<Range> a(n);
    vector<int> comp;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
        comp.push_back(a[i].l);
        comp.push_back(a[i].r);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto &r : a) {
        r.l = lower_bound(comp.begin(), comp.end(), r.l) - comp.begin() + 1;
        r.r = lower_bound(comp.begin(), comp.end(), r.r) - comp.begin() + 1;
    }
    sort(a.begin(), a.end(), [](Range &x, Range &y) {
        if (x.l != y.l) return x.l < y.l;
        return x.r > y.r;
    });
    int m = comp.size();
    Fenwick bit(m);
    vector<int> contained(n, 0);
    for (int i = 0; i < n; i++) {
        contained[a[i].idx] = bit.sum(m) - bit.sum(a[i].r - 1);
        bit.add(a[i].r, 1);
    }
    bit = Fenwick(m);
    vector<int> contains(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        contains[a[i].idx] = bit.sum(a[i].r);
        bit.add(a[i].r, 1);
    }
    for (int i = 0; i < n; i++) cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << contained[i] << ' ';
    cout << '\n';
    return 0;
}
