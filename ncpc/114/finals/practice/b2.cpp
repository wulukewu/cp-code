#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define ing long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

using uint = unsigned;
using ull = unsigned int long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;
const double EPS = 1e-9;

void solve(){
    int n;
    cin >> n;
    vector<int>p(n);
    FOR(i, 0, n) cin >> p[i];
    int k;
    cin >> k;

    int res = 0;
    int l = 0, r = 1e9+5;
    while(l<=r){
        int mid = l + (r-l)/2;
        int cnt = 1;
        int last = p[0];
        FOR(i, 1, n){
            // if(last==-1){
            //     last = p[i];
            //     continue;
            // }
            if(p[i]-last>mid){
                cnt++;
                last = p[i];
            }
        }
        // if(last<p[n-1]) cnt++;
        // cout << l << ' ' << r << ' ' << mid << ' ' << cnt << endl;
        if(cnt<=k){
            r = mid - 1;
            res = mid;
        }else{
            l = mid + 1;
        }
    }
    int ans = res * 2;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}