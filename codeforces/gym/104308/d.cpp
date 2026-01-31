// ==================================================
// Problem   : 104308D - Unknown
// Submission Result: Runtime of 390 ms and Memory usage of 0 KB
// Runtime   : 390 ms
// Memory    : 0 KB
// URL       : https://codeforces.com/contest/104308/problem/D
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

void solve(){

    int n,q;
    cin >> n >> q;
    vector<int> as(n),bs(q);
    FOR(i,0,n) cin >> as[i];
    sort(ALL(as));
    FOR(i,0,q) cin >> bs[i];

    // print(as);
    // print(bs);
    // cout << endl;

    for(auto num : bs){
        int ans = 0;
        for(int i=1;i*i<=num;i++){
            if(num % i == 0){
                auto it1 = binary_search(ALL(as), i);
                ans += (1-it1);
                if(i*i == num) break;
                auto it2 = binary_search(ALL(as), num/i);
                ans += (1-it2);
            }
        }
        cout << ans << endl;
    }

}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}