// ==================================================
// Problem   : ABC435_E - Cover query
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc435/tasks/abc435_e
// ==================================================

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
    int n, q;
    cin >> n >> q;

    map < int, int > mp;
    int cnt = 0;

    int l, r;
    FOR(qq, 0, q){
        cin >> l >> r;

        auto it = mp.upper_bound(l);
        if(it != mp.begin()) it--;

        while(it != mp.end()){
            int start = it->F;
            int end = it->S;

            if(start>r+1){
                break;
            }
            if(end<l-1){
                it++;
                continue;
            }

            l = min(l, start);
            r = max(r, end);
            cnt -= end-start+1;
            it = mp.erase(it);
        }

        cnt += r-l+1;
        mp[l] = r;

        cout << n - cnt << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
