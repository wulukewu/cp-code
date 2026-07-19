#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 100005;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y]) return pos[x] < pos[y];
    x += gap; y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa + N, comp);
        for (int i = 0; i < N - 1; i++) tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        for (int i = 0; i < N; i++) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N - 1) {
        int j = sa[pos[i] + 1];
        while (i + k < N && j + k < N && S[i + k] == S[j + k]) k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

pair<ll, ll> seg[mxN * 4];
int mark[mxN * 4];

void push(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].first = seg[2*k+1].first = seg[k].first / 2;
        seg[2*k].second = seg[2*k+1].second = 0;
        mark[2*k] = mark[2*k+1] = 1;
    }
}

void add(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return;
    if (a <= x && b >= y) {
        seg[k].second += v;
        return;
    }
    int h = min(b, y) - max(a, x) + 1;
    push(k);
    seg[k].first += h * v;
    int m = (x + y) / 2;
    add(v, a, b, 2*k, x, m);
    add(v, a, b, 2*k+1, m+1, y);
}

ll assign(ll v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return seg[k].first + (y - x + 1) * seg[k].second;
    if (a <= x && b >= y) {
        seg[k].first = (y - x + 1) * v;
        seg[k].second = 0;
        mark[k] = 1;
        return seg[k].first;
    }
    push(k);
    int m = (x + y) / 2;
    seg[2*k].second += seg[k].second;
    seg[2*k+1].second += seg[k].second;
    seg[k].second = 0;
    seg[k].first = assign(v, a, b, 2*k, x, m) + assign(v, a, b, 2*k+1, m+1, y);
    return seg[k].first;
}

ll query(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) return seg[k].first + (y - x + 1) * seg[k].second;
    push(k);
    seg[k].first += (y - x + 1) * seg[k].second;
    seg[2*k].second += seg[k].second;
    seg[2*k+1].second += seg[k].second;
    seg[k].second = 0;
    int m = (x + y) / 2;
    return query(a, b, 2*k, x, m) + query(a, b, 2*k+1, m+1, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S; N = S.size();
    suffix();
    build_lcp();
    ll k; cin >> k;
    int K = 1 << (int)ceil(log2(N + 1));
    k = (ll)N * (N + 1) / 2 - k + 1;
    ll cur = 0;
    for (int i = N - 1; i >= 0; i--) {
        add(1, 1, N - sa[i], 1, 0, K - 1);
        int prev = i ? lcp[i - 1] : 0;
        int l = prev + 1, r = N - sa[i], ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (cur + query(m, N - sa[i], 1, 0, K - 1) >= k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (ans != -1) {
            cout << S.substr(sa[i], ans) << '\n';
            return 0;
        }
        cur += query(prev + 1, N - sa[i], 1, 0, K - 1);
        assign(0, prev + 1, N - sa[i], 1, 0, K - 1);
    }
    return 0;
}
