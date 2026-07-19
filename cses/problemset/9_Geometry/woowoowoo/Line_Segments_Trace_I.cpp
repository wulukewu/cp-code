#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    void add_line(int idx, int l, int r, Line nw) {
        int m = (l + r) / 2;
        bool left = nw.eval(l) > nodes[idx].line.eval(l);
        bool mid = nw.eval(m) > nodes[idx].line.eval(m);
        if (mid) swap(nodes[idx].line, nw);
        if (l == r) return;
        if (left != mid) {
            if (nodes[idx].left == -1) nodes[idx].left = nodes.size(), nodes.emplace_back(Line(0, -INF));
            add_line(nodes[idx].left, l, m, nw);
        } else {
            if (nodes[idx].right == -1) nodes[idx].right = nodes.size(), nodes.emplace_back(Line(0, -INF));
            add_line(nodes[idx].right, m + 1, r, nw);
        }
    }
    void add_line(Line l) { add_line(0, xmin, xmax, l); }
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
    int n, m; cin >> n >> m;
    LiChao tree(0, m);
    for (int i = 0; i < n; i++) {
        ll y1, y2; cin >> y1 >> y2;
        ll slope = (y2 - y1) / m;
        tree.add_line(Line(slope, y1));
    }
    for (int x = 0; x <= m; x++) {
        cout << tree.query(x);
        if (x < m) cout << " ";
    }
    cout << "\n";
    return 0;
}
