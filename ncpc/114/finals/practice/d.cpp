#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define ing long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

using uint = unsigned;
using ull = unsigned int long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;
const double EPS = 1e-9;

void solve(){
    int f, w, n;
    cin >> f >> w >> n;
    vector<int>c(n);
    FOR(i, 0, n) cin >> c[i];

    int ans = 0;
    if(f==w){
        int cnt = 0;
        FOR(i, 0, n){
            cnt += c[i]/f;
        }
        ans = max(ans, cnt/3);
    }else if(f>w){
        Prior<pair<int, int>>pq;
        int cntf = 0, cntw = 0;
        FOR(i, 0, n){
            int cur = c[i];
            cntf += cur/f;
            cur %= f;
            cntw += cur/w;
            cur %= w;
            pq.push({cur, c[i]/f});
        }
        ans = max(ans, min(cntf, cntw/2));
        while(!pq.empty()){
            auto [rem, fc] = pq.top();
            pq.pop();
            if(fc==0) continue;
            int cur = rem+f;
            cntf--;
            cntw += cur/w;
            cur %= w;
            pq.push({cur, fc-1});
            ans = max(ans, min(cntf, cntw/2));
        }
    }else{
        Prior<pair<int, int>>pq;
        int cntf = 0, cntw = 0;
        FOR(i, 0, n){
            int cur = c[i];
            cntw += cur/w;
            cur %= w;
            cntf += cur/f;
            cur %= f;
            pq.push({cur, c[i]/w});
        }
        ans = max(ans, min(cntf, cntw/2));
        while(!pq.empty()){
            auto [rem, wc] = pq.top();
            pq.pop();
            if(wc==0) continue;
            int cur = rem+w;
            cntw--;
            cntf += cur/f;
            cur %= f;
            pq.push({cur, wc-1});
            ans = max(ans, min(cntf, cntw/2));
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}