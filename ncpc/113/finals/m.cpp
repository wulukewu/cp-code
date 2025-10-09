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



void solve(){
    int n;
    cin >> n;

    if(n==0){
        cout << 0 << endl;
    }

    FOR(nn, 0, n){
        int m;
        cin >> m;

        vector < int > v(m);
        FOR(i, 0, m){
            cin >> v[i];
        }

        int ans = 0;
        for(int i=m; i>=0; i--){
            if(v[i]>i+1){
                ans = i+1;
                break;
            }
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}

