#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void add(int idx, int val) {
        for(; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    } 

    int sum(int idx) const {
        int res = 0;
        for(; idx > 0; idx -= idx & -idx){
            res += bit[idx];
        }

        return res;
    }

    int kth(int k) const {
        int idx = 0;

        int pw = 1;
        while ((pw << 1) <= n){
            pw <<= 1;
        }

        for(int d = pw; d > 0; d >>= 1){
            int nxt = idx + d;
            if(nxt <= n && bit[nxt] < k){
                idx = nxt;
                k -= bit[nxt];
            }
        }
        return idx + 1;
    }


};

void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> s(n);

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    multiset<int> st;
    for(int x : s) st.insert(x);
    vector<int> slip(n);

    for(int i = n-1; i >= 0; i--){
        int capacity = n - 1 - i;

        auto it = st.upper_bound(capacity);

        if(it == st.begin()) {
            cout << -1 << endl;
            return;
        }

        --it;
        slip[i] = *it;
        st.erase(it);
    }

    sort(h.begin(), h.end());

    Fenwick fw(n);

    for(int i = 1; i <= n; i++){
        fw.add(i, 1);
    }

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int k = slip[i] + 1;
        
        int idx = fw.kth(k);

        ans[i] = h[idx -1];
        fw.add(idx, -1);
    }

    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << ans[i];
    }

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}