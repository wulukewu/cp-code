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
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res = 1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b){a = a*POW(b, MOD-2) % MOD;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

int gcd(int a, int b){
    if(a < b) swap(a,b);
    // cout << a << " " << b << endl;
    if(b == 1) return 1;
    if(a%b == 0) return b;
    else return gcd(b,a%b); 
}


void solve(){
    int people,candy;
    cin >> people >> candy;
    // cout << gcd(people,candy) << endl;
    int ans = 0;
    FOR(i,1,people+1){
        if(candy <= 0) break;
        ans += 1;
        int give = gcd(people,i);
        candy -= give;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

