#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    char val;
    int prio, sz;
    Node *l, *r;
    Node(char v) : val(v), prio(rng()), sz(1), l(nullptr), r(nullptr) {}
};

int sz(Node *t) { return t ? t->sz : 0; }
void upd(Node *t) { if (t) t->sz = 1 + sz(t->l) + sz(t->r); }

void split(Node *t, int k, Node *&a, Node *&b) {
    if (!t) { a = b = nullptr; return; }
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
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void print(Node *t) {
    if (!t) return;
    print(t->l);
    cout << t->val;
    print(t->r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; string s; cin >> n >> m >> s;
    Node *root = nullptr;
    for (char c : s) root = merge(root, new Node(c));
    while (m--) {
        int a, b; cin >> a >> b; a--;
        Node *l, *mid, *r;
        split(root, a, l, mid);
        split(mid, b - a, mid, r);
        root = merge(merge(l, r), mid);
    }
    print(root); cout << "\n";
    return 0;
}
