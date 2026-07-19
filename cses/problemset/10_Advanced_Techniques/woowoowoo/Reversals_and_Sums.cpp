#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int val;
    long long sum;
    int prio, sz;
    bool rev;
    Node *l, *r;
    Node(int v) : val(v), sum(v), prio(rng()), sz(1), rev(false), l(nullptr), r(nullptr) {}
};

int sz(Node *t) { return t ? t->sz : 0; }
long long sum(Node *t) { return t ? t->sum : 0; }

void upd(Node *t) {
    if (t) {
        t->sz = 1 + sz(t->l) + sz(t->r);
        t->sum = t->val + sum(t->l) + sum(t->r);
    }
}

void push(Node *t) {
    if (t && t->rev) {
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
        t->rev = false;
    }
}

void split(Node *t, int k, Node *&a, Node *&b) {
    if (!t) { a = b = nullptr; return; }
    push(t);
    if (sz(t->l) >= k) {
        b = t;
        split(t->l, k, a, b->l);
        upd(b);
    } else {
        a = t;
        split(t->r, k - sz(t->l) - 1, a->r, b);
        upd(a);
    }
}

Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    if (a->prio > b->prio) {
        push(a);
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = merge(root, new Node(x));
    }
    while (m--) {
        int t, a, b; cin >> t >> a >> b; a--;
        Node *l, *mid, *r;
        split(root, a, l, mid);
        split(mid, b - a, mid, r);
        if (t == 1) {
            mid->rev ^= true;
        } else {
            cout << sum(mid) << "\n";
        }
        root = merge(merge(l, mid), r);
    }
    return 0;
}
