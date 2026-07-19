#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int sum;
    Node *left, *right;
    Node(int x) {
        sum = x;
        left = right = nullptr;
    }
    Node(Node *l, Node *r) {
        left = l;
        right = r;
        sum = 0;
        if (left) sum += left->sum;
        if (right) sum += right->sum;
    }
};

int get_sum(Node *p) {
    return p ? p->sum : 0;
}
Node *get_left(Node *p) {
    return p ? p->left : nullptr;
}
Node *get_right(Node *p) {
    return p ? p->right : nullptr;
}

Node* update(int nl, int nr, Node *ver, int pos, int delta) {
    if (nl == nr) {
        return new Node(delta + get_sum(ver));
    }
    int mid = nl + (nr - nl) / 2;
    if (pos <= mid)
        return new Node(update(nl, mid, get_left(ver), pos, delta), get_right(ver));
    else
        return new Node(get_left(ver), update(mid + 1, nr, get_right(ver), pos, delta));
}

int query(int nl, int nr, Node *ver, Node *ver2, int x, int y) {
    if (!ver) return 0;
    if (nl >= x && nr <= y) return get_sum(ver) - get_sum(ver2);
    if (nl > y || nr < x) return 0;
    int mid = nl + (nr - nl) / 2;
    return query(nl, mid, get_left(ver), get_left(ver2), x, y) +
           query(mid + 1, nr, get_right(ver), get_right(ver2), x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1), all;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        all.push_back(v[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++)
        v[i] = lower_bound(all.begin(), all.end(), v[i]) - all.begin();
    const int NODES = 200010;
    Node *roots[NODES];
    roots[0] = nullptr;
    for (int i = 1; i <= n; i++)
        roots[i] = update(0, NODES - 1, roots[i - 1], v[i], 1);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int lc = lower_bound(all.begin(), all.end(), c) - all.begin();
        int rd = upper_bound(all.begin(), all.end(), d) - all.begin() - 1;
        cout << query(0, NODES - 1, roots[b], roots[a - 1], lc, rd) << '\n';
    }
    return 0;
}
