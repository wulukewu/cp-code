#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3fLL;
const int SIZE = 800000;

int N, Q, lo[SIZE], hi[SIZE];
ll sum[SIZE], dp[SIZE], dpl[SIZE], dpr[SIZE];

struct Node {
    ll sum, pref, suff, best;
    Node() : sum(0), pref(0), suff(0), best(0) {}
    Node(ll s, ll p, ll su, ll b) : sum(s), pref(p), suff(su), best(b) {}
};

Node combine(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suff = max(b.suff, b.sum + a.suff);
    res.best = max(max(a.best, b.best), a.suff + b.pref);
    return res;
}

void pull(int i) {
    dpl[i] = max(dpl[2 * i], sum[2 * i] + dpl[2 * i + 1]);
    dpr[i] = max(dpr[2 * i + 1], sum[2 * i + 1] + dpr[2 * i]);
    dp[i] = max(dpr[2 * i] + dpl[2 * i + 1], max(dp[2 * i], dp[2 * i + 1]));
    sum[i] = sum[2 * i] + sum[2 * i + 1];
}

void build(int i, int l, int r) {
    lo[i] = l; hi[i] = r;
    if (l == r) {
        cin >> sum[i];
        dpl[i] = dpr[i] = dp[i] = sum[i];
        return;
    }
    int m = l + (r - l) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    pull(i);
}

Node query(int i, int l, int r) {
    if (lo[i] > r || hi[i] < l) return Node(0, -INF, -INF, -INF);
    if (lo[i] >= l && hi[i] <= r) return Node(sum[i], dpl[i], dpr[i], dp[i]);
    Node left = query(2 * i, l, r);
    Node right = query(2 * i + 1, l, r);
    return combine(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    build(1, 1, N);
    for (int q = 0, l, r; q < Q; q++) {
        cin >> l >> r;
        Node res = query(1, l, r);
        cout << (res.best <= 0 ? 0 : res.best) << '\n';
    }
    return 0;
}
