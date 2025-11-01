#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
//#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;} 
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
template <typename T>
void printQ(queue < T > q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
template <typename T>
void printPQ(priority_queue < T > pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    set < int > st;
    st.insert(0);
    map < int, int > mp;
    mp[0] = INT_MAX;

    int ans = INT_MAX;
    int x, l, r;
    FOR(i, 0, n){
        cin >> x;
        st.insert(x);
        l = *(--st.lower_bound(x));
        if(st.upper_bound(x)==st.end()) r = INT_MAX;
        else r = *st.upper_bound(x);
        // cout << l << ' ' << r << endl;

        if(mp[l]>abs(x-l)){
            ans -= mp[l];
            mp[l] = abs(x-l);
            ans += mp[l];
        }
        if(mp[r]>abs(x-r)){
            ans -= mp[r];
            mp[r] = abs(x-r);
            ans += mp[r];
        }
        mp[x] = min(abs(x-l), abs(x-r));
        ans += mp[x];
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
