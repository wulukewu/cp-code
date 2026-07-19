#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

struct LiChao {
    struct Node {
        ll m, b;
        int left, right;
        Node(ll m = 0, ll b = 0) : m(m), b(b), left(-1), right(-1) {}
    };
    vector<Node> nodes;
    int xl, xr;
    LiChao(int xl, int xr) : xl(xl), xr(xr) {
        nodes.emplace_back(0, 0);
    }
    void add_line(int idx, int l, int r, ll m, ll b, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            int mid = (l + r) / 2;
            bool left = m * l + b > nodes[idx].m * l + nodes[idx].b;
            bool midc = m * mid + b > nodes[idx].m * mid + nodes[idx].b;
            if (midc) {
                swap(nodes[idx].m, m);
                swap(nodes[idx].b, b);
            }
            if (l == r) return;
            if (left != midc) {
                if (nodes[idx].left == -1) nodes[idx].left = nodes.size(), nodes.emplace_back(0, 0);
                add_line(nodes[idx].left, l, mid, m, b, ql, qr);
            } else {
                if (nodes[idx].right == -1) nodes[idx].right = nodes.size(), nodes.emplace_back(0, 0);
                add_line(nodes[idx].right, mid + 1, r, m, b, ql, qr);
            }
            return;
        }
        int mid = (l + r) / 2;
        if (ql <= mid) {
            if (nodes[idx].left == -1) nodes[idx].left = nodes.size(), nodes.emplace_back(0, 0);
            add_line(nodes[idx].left, l, mid, m, b, ql, qr);
        }
        if (qr > mid) {
            if (nodes[idx].right == -1) nodes[idx].right = nodes.size(), nodes.emplace_back(0, 0);
            add_line(nodes[idx].right, mid + 1, r, m, b, ql, qr);
        }
    }
    void add_line(ll m, ll b, int ql, int qr) {
        if (ql > qr) return;
        ql = max(ql, xl);
        qr = min(qr, xr);
        if (ql > qr) return;
        add_line(0, xl, xr, m, b, ql, qr);
    }
    ll query(int idx, int l, int r, int x) {
        if (idx == -1) return 0;
        int mid = (l + r) / 2;
        ll cur = nodes[idx].m * x + nodes[idx].b;
        if (l == r) return cur;
        if (x <= mid) return max(cur, query(nodes[idx].left, l, mid, x));
        else return max(cur, query(nodes[idx].right, mid + 1, r, x));
    }
    ll query(int x) { return query(0, xl, xr, x); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
    set<int> s;
    for (int i = -1; i <= n; i++) s.insert(i);
    LiChao lt(0, n - k);
    for (auto it = pos.rbegin(); it != pos.rend(); it++) {
        int v = it->first;
        for (int i : it->second) s.erase(i);
        for (int i : it->second) {
            auto it2 = s.upper_bound(i);
            int l = *prev(it2) + 1;
            int r = *it2 - 1;
            if (r - k + 1 >= 0) {
                lt.add_line(v, (ll)(k - l) * v, max(0, l - k + 1), min(l, r - k + 1));
            }
            if (r - l + 1 >= k) {
                lt.add_line(0, (ll)k * v, l, r - k + 1);
            }
            lt.add_line(-v, (ll)(r + 1) * v, max(l, r - k + 1), r);
        }
    }
    for (int i = 0; i + k <= n; i++) {
        if (i) cout << " ";
        cout << lt.query(i);
    }
    cout << "\n";
    return 0;
}
