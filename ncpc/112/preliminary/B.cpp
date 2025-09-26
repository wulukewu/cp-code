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
void addmod(ll &a, ll b){a = (a+b)%MOD;}
void submod(ll &a, ll b){a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b){a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}

template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n,div;
    cin >> n;
    vector<int> dp(n+1,0);
    FOR(i,0,n){
        cin >> dp[i+1];
    }
    cin >> div;
    // cout << "0 ";
    FOR(i,1,n+1){
        dp[i] = (dp[i] + dp[i-1]) % div;
        // cout << dp[i] << " ";
    }
    // cout << endl;
    vector<int> ans(div);
    FOR(i,0,n){
        FOR(j,i+1,n+1){
            int count = dp[j]-dp[i];
            if(count < 0) count += div;
            // cout << i << " " << j << " " << count << endl;
            ans[count] += 1;
        }
    }
    // print(ans);
    for(int i = div-1;i>=0;i--){
        if(ans[i] != 0){
            cout << ans[i];
            break;
        }
    }

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}