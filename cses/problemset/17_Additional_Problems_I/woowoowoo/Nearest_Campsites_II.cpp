#include <bits/stdc++.h>
using namespace std;

struct compress {
  vector<int> v;
  int n;
  compress(vector<int> _v) : v(_v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
  }
  int operator()(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }
};

struct segtree {
  int n;
  vector<int> seg;
  segtree(int n) : n(n), seg(2 * n, 1e9) {}
  void update(int idx, int x) {
    idx += n;
    seg[idx] = x;
    while (idx /= 2) seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
  }
  int query(int l, int r) {
    if (l > r) return 1e9;
    int res = 1e9;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, seg[l++]);
      if (r & 1) res = min(res, seg[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<pair<int,int>> a(n), b(m);
  for (auto &p : a) cin >> p.first >> p.second;
  for (auto &p : b) cin >> p.first >> p.second;
  vector<int> ys;
  for (auto &p : a) ys.push_back(p.second);
  for (auto &p : b) ys.push_back(p.second);
  compress comp(ys);
  vector<int> ans(m, 1e9);
  struct Event { int x, y, type, val, idx; };
  // Case 1: x_r >= x_f && y_r >= y_f  -> dist = (x_r+y_r) - (x_f+y_f)
  {
    vector<Event> events;
    for (auto &p : a) events.push_back({p.first, p.second, 0, p.first + p.second, -1});
    for (int i = 0; i < m; i++) events.push_back({b[i].first, b[i].second, 1, b[i].first + b[i].second, i});
    sort(events.begin(), events.end(), [](Event &A, Event &B) {
      if (A.x != B.x) return A.x > B.x;
      return A.type < B.type;
    });
    segtree st(comp.n);
    for (auto &ev : events) {
      if (ev.type == 0) st.update(comp(ev.y), ev.val);
      else {
        int res = st.query(comp(ev.y), comp.n - 1);
        if (res < 1e9) ans[ev.idx] = min(ans[ev.idx], res - ev.val);
      }
    }
  }
  // Case 2: x_r >= x_f && y_r <= y_f  -> dist = (x_r-y_r) - (x_f-y_f)
  {
    vector<Event> events;
    for (auto &p : a) events.push_back({p.first, p.second, 0, p.first - p.second, -1});
    for (int i = 0; i < m; i++) events.push_back({b[i].first, b[i].second, 1, b[i].first - b[i].second, i});
    sort(events.begin(), events.end(), [](Event &A, Event &B) {
      if (A.x != B.x) return A.x > B.x;
      return A.type < B.type;
    });
    segtree st(comp.n);
    for (auto &ev : events) {
      if (ev.type == 0) st.update(comp(ev.y), ev.val);
      else {
        int res = st.query(0, comp(ev.y));
        if (res < 1e9) ans[ev.idx] = min(ans[ev.idx], res - ev.val);
      }
    }
  }
  // Case 3: x_r <= x_f && y_r >= y_f  -> dist = (-x_r+y_r) - (-x_f+y_f)
  {
    vector<Event> events;
    for (auto &p : a) events.push_back({p.first, p.second, 0, -p.first + p.second, -1});
    for (int i = 0; i < m; i++) events.push_back({b[i].first, b[i].second, 1, -b[i].first + b[i].second, i});
    sort(events.begin(), events.end(), [](Event &A, Event &B) {
      if (A.x != B.x) return A.x < B.x;
      return A.type < B.type;
    });
    segtree st(comp.n);
    for (auto &ev : events) {
      if (ev.type == 0) st.update(comp(ev.y), ev.val);
      else {
        int res = st.query(comp(ev.y) + 1, comp.n - 1);
        if (res < 1e9) ans[ev.idx] = min(ans[ev.idx], res - ev.val);
      }
    }
  }
  // Case 4: x_r <= x_f && y_r <= y_f  -> dist = (-x_r-y_r) - (-x_f-y_f)
  {
    vector<Event> events;
    for (auto &p : a) events.push_back({p.first, p.second, 0, -p.first - p.second, -1});
    for (int i = 0; i < m; i++) events.push_back({b[i].first, b[i].second, 1, -b[i].first - b[i].second, i});
    sort(events.begin(), events.end(), [](Event &A, Event &B) {
      if (A.x != B.x) return A.x < B.x;
      return A.type < B.type;
    });
    segtree st(comp.n);
    for (auto &ev : events) {
      if (ev.type == 0) st.update(comp(ev.y), ev.val);
      else {
        int res = st.query(0, comp(ev.y));
        if (res < 1e9) ans[ev.idx] = min(ans[ev.idx], res - ev.val);
      }
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i + 1 == m];
}
