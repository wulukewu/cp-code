// ==================================================
// Problem   : 2182D - Christmas Tree Decoration
// Tags      : combinatorics, dp, greedy, math
// Runtime   : 78 ms
// Memory    : 0 KB
// URL       : https://codeforces.com/contest/2182/problem/D
// ==================================================

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
const ll MOD = 998244353;
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

void solve() {
    vector<int>frac(60, 1);
    FOR(i, 2, 60){
        // frac[i] = frac[i-1] * i;
        frac[i] = frac[i-1];
        timesmod(frac[i], i);
    }
    // print(frac);

    auto ch = [&](int a, int b) -> int {
        int ans = frac[a];
        dividemod(ans, frac[b]);
        dividemod(ans, frac[a-b]);
        return ans;
    };

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
    
        vector<int>arr(n+1);
        int sum = 0;
        FOR(i, 0, n+1){
            cin >> arr[i];
            sum+=arr[i];
        }
    
        int base = sum / n;
        int rem = sum % n;
        // int a2 = sum % n;
        // int a1 = n - a2;
        // cout << "a1a2=" << a1 << ' ' << a2 << endl;

        // FOR(i, 1, n+1){
        //     int x = base - arr[i];
        //     if(x>0){
        //         arr[i] += x;
        //         arr[0] -= x;
        //     }
        // }
        // print(arr);
        // if(arr[0]<0){
        //     cout << 0 << endl;
        //     continue;
        // }

        int cnt = 0;
        bool det = true;
        FOR(i, 1, n+1){
            if(arr[i]>base+1){
                det = false;
                break;
            }
            if(arr[i]==base+1){
                cnt++;
            }
        }

        if(!det or cnt>rem){
            cout << 0 << endl;
            continue;
        }

        int ans = frac[rem];
        dividemod(ans, frac[rem-cnt]);
        timesmod(ans, frac[n-cnt]);
        // int ans = ch(a1+arr[0], arr[0]);
        // timesmod(ans, frac[a2]);
        // timesmod(ans, frac[a1]);
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
