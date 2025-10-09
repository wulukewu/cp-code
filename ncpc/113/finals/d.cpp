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



void solve(){
    int n;
    cin >> n;

    vector < int > v(n);
    FOR(i, 0, n) cin >> v[i];

    bool ans = false;
    auto dfs = [&](auto&& self, int d, int ai, int aj, int ak) -> void {
        if(d>=n) return;
        if(ans) return;
        // cout << d << ' ' << ai << ' ' << aj << ' ' << ak << endl;

        if(ai==-1){
            self(self, d+1, d, aj, ak);
        }else if(aj==-1){
            if(v[d]>v[ai]){
                self(self, d+1, ai, d, ak);
            }else{
                self(self, d+1, ai, aj, ak);
            }
        }else{ // ai<aj!=-1
            if(v[d]>v[aj]){
                self(self, d+1, aj, d, ak);
            }else if(v[d]>v[ai]){
                self(self, d+1, ai, aj, ak);
                self(self, d+1, aj, -1, ak);
                self(self, d+1, d, -1, ak);
            }else{
                ans = true;
                cout << "yes " << ai+1 << ' ' << aj+1 << ' ' << d+1 << endl;
            }
        }
    };

    dfs(dfs, 0, -1, -1, -1);
    if(!ans){
        cout << "no" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

