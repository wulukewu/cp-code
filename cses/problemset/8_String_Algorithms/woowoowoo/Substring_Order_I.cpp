#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void build_sa(const string& s, vector<int>& sa, vector<int>& rank) {
    int n = s.size();
    sa.resize(n);
    rank.resize(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j) { return s[i] < s[j]; });
    rank[sa[0]] = 0;
    for (int i = 1; i < n; i++) rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    vector<int> tmp(n), cnt(n);
    for (int k = 1; k < n; k <<= 1) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) cnt[rank[i]]++;
        partial_sum(cnt.begin(), cnt.end(), cnt.begin());
        for (int i = n - 1; i >= 0; i--) {
            int j = (sa[i] - k + n) % n;
            tmp[--cnt[rank[j]]] = j;
        }
        swap(sa, tmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            int cur = sa[i], prev = sa[i - 1];
            int cur_k = (cur + k) % n, prev_k = (prev + k) % n;
            tmp[cur] = tmp[prev] + (rank[cur] != rank[prev] || rank[cur_k] != rank[prev_k]);
        }
        swap(rank, tmp);
        if (rank[sa.back()] == n - 1) break;
    }
}

void build_lcp(const string& s, const vector<int>& sa, const vector<int>& rank, vector<int>& lcp) {
    int n = s.size();
    lcp.resize(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
        lcp[rank[i] - 1] = h;
        if (h > 0) h--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    vector<int> sa, rank;
    build_sa(s, sa, rank);
    vector<int> lcp;
    build_lcp(s, sa, rank, lcp);
    for (int i = 0; i < n; i++) {
        ll pos = sa[i];
        ll cnt = n - pos - (i > 0 ? lcp[i - 1] : 0);
        if (k <= cnt) {
            cout << s.substr(pos, (i > 0 ? lcp[i - 1] : 0) + k) << '\n';
            return 0;
        }
        k -= cnt;
    }
    return 0;
}
