// ==================================================
// Problem   : jtU6D2hVEiD - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/D
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

void solve() {
    int n;
    cin >> n;

    map < int, bool > mp;

    auto dfs = [&](int p, bool who, auto&& self) -> bool {
        if(p>=n){
            // if(who) return false;
            // else return true;
            return !who;
        }

        bool win, res;
        if(who){
            win = false;
            for(int i=2; i<=9; i++){
                // win = win or self(p*i, !who, self);
                if(mp.find(p*i)==mp.end()){
                    res = self(p*i, !who, self);
                    mp[p*i] = res;
                }else{
                    res = mp[p*i];
                }
                win = win or res;
            }
        }else{
            win = true;
            for(int i=2; i<=9; i++){
                // win = win and !self(p*i, !who, self);
                if(mp.find(p*i)==mp.end()){
                    res = self(p*i, !who, self);
                    mp[p*i] = !res;
                }else{
                    res = !mp[p*i];
                }
                win = win and res;
            }
        }
        return win;
    };

    bool ans = dfs(1, true, dfs);
    if(ans){
        cout << "Stan wins." << endl;
    }else{
        cout << "Ollie wins." << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
