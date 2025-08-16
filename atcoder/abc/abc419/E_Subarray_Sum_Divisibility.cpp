#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
//#define int long long
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

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];

    vector < int > brr(n, 0);

    // int ans = 0;
    int sum_s = 0;
    int s, j, k;
    FOR(i, 0, l){
        s = 0;
        j = 0;
        k = i;
        while(k < n){
            // cout << k << endl;
            s = max(s, arr[k]);

            j++;
            k = i + l * j;
        }
        sum_s += s;
        cout << s << endl;

        j = 0;
        k = i;
        while(k < n){
            // cout << k << endl;
            // ans += s - arr[k];
            brr[k] += s - arr[k];
            j++;
            k = i + l * j;
        }
    }
    print(brr);
    // cout << ans << endl;
    cout << sum_s << endl;

    // int max_s = 0;
    // vector < int > sv(l);
    // FOR(i, 0, l){
    //     int s = 0;
    //     int j = 0;
    //     int k = i;
    //     while(k < n){
    //     // FOR(j, 0, l){
    //         // cout << k << endl;
    //         s += arr[k];

    //         j++;
    //         k = i + l * j;
    //     }
    //     s %= m;
    //     if(s==0) s = m;
    //     max_s = max(max_s, s);
    //     // cout << s << endl;
    //     sv[i] = s;
    // }
    // cout << max_s << endl;

    // int ans = 0;
    // FOR(i, 0, l){
    //     ans += max_s - sv[i];
    // }
    // cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
