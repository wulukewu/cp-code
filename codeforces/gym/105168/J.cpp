// ==================================================
// Problem   : 105168J - Unknown
// URL       : https://codeforces.com/contest/105168/problem/J
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
// #define float double
// #define float long double
#define FOR(i, a ,b) for(int i = a; i< b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve(){
    int k;
    cin >> k;

    string s;
    cin >> s;

    vector < int > dp(k+1);
    dp[0] = 1;
    FOR(i, 1, k+1){
        dp[i] = dp[i-1] * 2;
        dp[i] %= 998244353;
    }
    // print(dp);

    int t = 0;
    FOR(i, 0, k){
        if(s[i]=='?') t++;
    }
    // cout << t << endl;

    int q;
    cin >> q;

    int p;
    char c;
    while(q--){
        cin >> p >> c;
        p--;
        if(s[p]=='?' and c!='?') t--;
        else if(s[p]!='?' and c=='?') t++;
        s[p] = c;

        cout << dp[t] << endl;
    }
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}