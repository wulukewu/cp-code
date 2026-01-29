// ==================================================
// Problem   : 105168D2 - Unknown
// URL       : https://codeforces.com/contest/105168/problem/D2
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
    int n, k;
    cin >> n >> k;

    map < int, int > mp;
    FOR(i, 0, n){
        int a;
        cin >> a;
        mp[a]++;
    }

    int ans = 0;
    set<int> visited;
    for(auto &[x, cx] : mp){
        int tar = k ^ x;
        if(mp.find(tar) == mp.end()){
            continue;
        }

        if(tar == x){
            ans += cx * (cx -1 ) / 2;
        }else if(!visited.count(tar)){
            ans += cx * mp[tar];
        }
        visited.insert(x);
    }

    cout << ans << endl;

}

signed main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}