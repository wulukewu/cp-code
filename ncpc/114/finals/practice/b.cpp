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
    vector<int> locate(n);
    for(int i=0;i<n;i++) cin >> locate[i];
    int k;
    cin >> k;
    int ans = locate[n-1]+7 , l = 1 , r = locate[n-1] - locate[0] , mid = (l+r)/2;
    while(l<=r){
        mid = (l+r)/2;
        int used = 0 , time = 0 , from = 0 , now = 1;
        while(now < n && used < k){
            // time = locate[now] - locate[from];
            if(locate[now] - locate[from] > mid){
                // time = 0;
                from = now;
                used++;
            }
            now++;
        }
        if(now != n){
            l = mid+1;
        }
        else{
            ans = min(ans,mid);
            r = mid-1;
        }
    }
    cout << ans*2;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}