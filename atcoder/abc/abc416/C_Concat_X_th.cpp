// ==================================================
// Problem   : ABC416_C - Concat (X-th)
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc416/tasks/abc416_c
// ==================================================

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
//#define int long long
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
    int n, k, x;
    cin >> n >> k >> x;

    vector < string > s(n);
    FOR(i, 0, n) cin >> s[i];

    queue < pair < int, string > > q;
    q.push(make_pair(0, ""));
    vector < string > ans;

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        if(t.F==k){
            ans.PB(t.S);
            continue;
        }

        FOR(i ,0, n){
            q.push(make_pair(t.F+1, t.S+s[i]));
        }
    }

    sort(ALL(ans));
    // print(ans);
    cout << ans[x-1] << endl;


    // sort(ALL(s));
    // // print(s);

    // vector < int > v(k);
    // int t = x - 1;

    // for(int i=k-1; i>=0; i--){
    //     v[i] = t % n;
    //     t /= n;
    // }
    // // print(v);

    // string ans = "";
    // for(int i: v){
    //     ans += s[i];
    // }
    // cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
