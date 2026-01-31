// ==================================================
// Problem   : 105168C - Unknown
// Submission Result: Runtime of 171 ms and Memory usage of 100 KB
// Runtime   : 171 ms
// Memory    : 100 KB
// URL       : https://codeforces.com/contest/105168/problem/C
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
    int n,m;
    cin >> n >> m;
    int a,b;
    FOR(i,0,m) cin >> a >> b;
    cout << n << " ";
    FOR(i,0,n) cout << i+1 << " ";
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}