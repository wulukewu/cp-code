#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Line {
    ll m, b;
    Line(ll m = 0, ll b = -INF) : m(m), b(b) {}
    ll eval(ll x) const { return m * x + b; }
};

struct LiChao {
    struct Node {
        Line line;
        int left, right;
        Node(Line l) : line(l), left(-1), right(-1) {}
    };
    vector<Node> nodes;
    int xmin, xmax;
    LiChao(int xmin, int xmax) : xmin(xmin), xmax(xmax) {
        nodes.emplace_back(Line(0, -INF));
    }
    void add_line(int idx, int l, int r, Line nw, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            int m = (l + r) / 2;
            bool left = nw.eval(l) > nodes[idx].line.eval(l);
            bool mid = nw.eval(m) > nodes[idx].line.eval(m);
            if (mid) swap(nodes[idx].line, nw);
            if (l == r) return;
            if (left != mid) {
                if (nodes[idx].left == -1) nodes[idx].left = nodes.size(), nodes.emplace_back(Line(0, -INF));
                add_line(nodes[idx].left, l, m, nw, ql, qr);
            } else {
                if (nodes[idx].right == -1) nodes[idx].right = nodes.size(), nodes.emplace_back(Line(0, -INF));
                add_line(nodes[idx].right, m + 1, r, nw, ql, qr);
            }
            return;
        }
        int m = (l + r) / 2;
        if (ql <= m) {
            if (nodes[idx].left == -1) nodes[idx].left = nodes.size(), nodes.emplace_back(Line(0, -INF));
            add_line(nodes[idx].left, l, m, nw, ql, qr);
        }
        if (qr > m) {
            if (nodes[idx].right == -1) nodes[idx].right = nodes.size(), nodes.emplace_back(Line(0, -INF));
            add_line(nodes[idx].right, m + 1, r, nw, ql, qr);
        }
    }
    void add_line(Line l, int ql, int qr) { add_line(0, xmin, xmax, l, ql, qr); }
    ll query(int idx, int l, int r, ll x) {
        if (idx == -1) return -INF;
        int m = (l + r) / 2;
        ll cur = nodes[idx].line.eval(x);
        if (l == r) return cur;
        if (x <= m) return max(cur, query(nodes[idx].left, l, m, x));
        else return max(cur, query(nodes[idx].right, m + 1, r, x));
    }
    ll query(ll x) { return query(0, xmin, xmax, x); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    LiChao tree(0, 100000);
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            ll a, b, l, r; cin >> a >> b >> l >> r;
            tree.add_line(Line(a, b), l, r);
        } else {
            ll x; cin >> x;
            ll res = tree.query(x);
            if (res == -INF) cout << "NO\n";
            else cout << res << "\n";
        }
    }
    return 0;
}
