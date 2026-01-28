// ==================================================
// Problem   : 104308i.cpp - Unknown
// URL       : https://codeforces.com/contest/104308/problem/i.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
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
ll POW(ll a, ll b) { ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1);return res;}
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

int n, q, m;
vector < int > v;
vector < int > pos;
vector < int > top;

int lb(int x){
    return x & -x;
}

void add(int x, int y){
    for(int i=x; i<=m; i+=lb(i)){
        v[i] += y;
    }
}

int sum(int x){
    int res = 0;
    for(int i=x; i>0; i-=lb(i)){
        res += v[i];
    }
    return res;
}

void solve(){
    cin >> n >> q;
    m = n + q + 10;

    v = vector < int > (m, 0);
    pos = vector < int > (m, -1);
    top = vector < int > (m, -1);

    FOR(i, 0, n){
        cin >> v[i];
    }
    // print(v);

    FOR(i, 0, n){
        if(top[v[i]]==-1) top[v[i]]=i;
    }
    // print(top);

    FOR(i, 0, n){
        pos[i] = q+i+1;
        add(pos[i], 1);
    }
    // print(pos);

    int t = q+5;
    int d;
    while(q--){
        cin >> d;
        int top_cur = top[d];
        int pos_cur = pos[top_cur];
        cout << sum(pos_cur) << endl;
        t--;
        add(pos_cur, -1);
        pos[top_cur] = t;
        add(t, 1);
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}