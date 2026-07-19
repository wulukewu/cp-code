#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxN = 200001;
const int SIZE = 800000;

int N, Q, lo[SIZE], hi[SIZE];
ll a[maxN], ass[SIZE], mx[SIZE], sm[SIZE], ans[maxN];
vector<pair<int,int>> queries[maxN];

int len(int i) {
    return hi[i] - lo[i] + 1;
}

void assign_val(int i, ll val) {
    ass[i] = mx[i] = val;
    sm[i] = val * len(i);
}

void push(int i) {
    if (ass[i]) {
        assign_val(2 * i, ass[i]);
        assign_val(2 * i + 1, ass[i]);
        ass[i] = 0;
    }
}

void pull(int i) {
    sm[i] = sm[2 * i] + sm[2 * i + 1];
    mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

void init(int i, int l, int r) {
    lo[i] = l; hi[i] = r;
    if (l == r) {
        sm[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    init(2 * i, l, m);
    init(2 * i + 1, m + 1, r);
    pull(i);
}

void update(int i, int l, int r, ll val) {
    if (l > hi[i] || r < lo[i]) return;
    if (l <= lo[i] && hi[i] <= r) {
        assign_val(i, val);
        return;
    }
    push(i);
    update(2 * i, l, r, val);
    update(2 * i + 1, l, r, val);
    pull(i);
}

int orderOf(int i, int l, int val) {
    if (lo[i] == hi[i]) return lo[i];
    push(i);
    int idx;
    if (hi[2 * i] <= l || mx[2 * i] < val)
        idx = orderOf(2 * i + 1, l, val);
    else
        idx = orderOf(2 * i, l, val);
    pull(i);
    return idx;
}

ll sum(int i, int l, int r) {
    if (l > hi[i] || r < lo[i]) return 0;
    if (l <= lo[i] && hi[i] <= r) return sm[i];
    push(i);
    ll left = sum(2 * i, l, r);
    ll right = sum(2 * i + 1, l, r);
    pull(i);
    return left + right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    init(1, 1, N);
    for (int q = 0, l, r; q < Q; q++) {
        cin >> l >> r;
        queries[l].push_back({r, q});
    }
    for (int i = 2; i <= N; i++) a[i] += a[i - 1];
    for (int l = N; l >= 1; l--) {
        int val = a[l] - a[l - 1];
        int modifyR = (mx[1] < val) ? N + 1 : orderOf(1, l, val);
        update(1, l, modifyR - 1, val);
        for (auto &p : queries[l]) {
            int r = p.first;
            int id = p.second;
            ans[id] = sum(1, l, r) - (a[r] - a[l - 1]);
        }
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
    return 0;
}
