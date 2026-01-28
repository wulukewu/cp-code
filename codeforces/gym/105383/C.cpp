// ==================================================
// Problem   : 105383C.cpp - Unknown
// URL       : https://codeforces.com/contest/105383/problem/C.cpp
// ==================================================

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define endl '\n'
//#define int long long
//#define float double
//#define float long double
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
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    vector < pair < int, int > > v(n);
    FOR(i, 0, n){
        cin >> v[i].F;
    }
    FOR(i, 0, n){
        cin >> v[i].S;
    }

    map < int, int > mp;
    FOR(i, 0, n){
        mp.insert({v[i].F, v[i].S});
    }

    vector < bool > visit(n, false);
    int x = v[0].S;
    visit[0] = true;
    bool ans = true;
    vector < pair < int, int > > arr;
    arr.PB({v[0].F, v[0].S});
    while(x != v[0].F){
        visit[x] = true;
        int y = mp[x];
        if(visit[y]){
            ans = false;
            break;
        }
        arr.PB({x, y});
        x = y;
        // cout << x << endl;
    }

    if(ans){
        cout << "Yes" << endl;
        FOR(i, 0, n){
            cout << arr[i].F << ' ';
        }
        cout << endl;
        FOR(i, 0, n){
            cout << arr[i].S << ' ';
        }
    }else{
        cout << "No" << endl;
    }


}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
