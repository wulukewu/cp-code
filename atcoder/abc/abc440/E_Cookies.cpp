#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
//#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
template <typename T>
void printQ(queue < T > q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
template <typename T>
void printPQ(priority_queue < T > pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];

    sort(ALL(arr));
    reverse(ALL(arr));

    vector<int>brr(n-1);
    FOR(i, 0, n-1){
        brr[i] = arr[0] - arr[i+1];
    }

    int ans = arr[0] * k;
    cout << ans << endl;
    if(n==1){
        FOR(i, 0, x-1){
            cout << ans << endl;
        }
        return;
    }

    prior<pair<int, pair<int, int>>>pq;
    pq.push({brr[0], {0, 1}});

    FOR(i, 0, x-1){
        auto t = pq.top();
        pq.pop();

        int val = t.F;
        int last = t.S.F;
        int cnt = t.S.S;

        cout << ans - val << endl;

        if(cnt<k){
            pq.push({val+brr[last], {last, cnt+1}});
        }
        if(last+1<n-1){
            pq.push({val-brr[last]+brr[last+1], {last+1, cnt}});
        }
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
