// ==================================================
// Problem   : 2178D - Xmas or Hysteria
// Tags      : constructive algorithms, greedy, implementation, math
// URL       : https://codeforces.com/contest/2178/problem/D
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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>>arr(n);
    FOR(i, 0, n){
        arr[i].F = i+1;
        cin >> arr[i].S;
    }

    if(m==0){
        sort(ALL(arr), [&](pair<int,int>p1, pair<int,int>p2) -> bool {
            return p1.S < p2.S;
        });

        int sum = 0;
        FOR(i, 0, n-1) sum += arr[i].S;

        if(sum+arr[n-2].S<arr[n-1].S){
            cout << -1 << endl;
            return;
        }

        int l1 = arr[n-1].S;
        int l2 = arr[n-2].S;

        vector<pair<int,int>>brr;
        FOR(i, 0, n-2){
            if(l1>arr[i].S){
                brr.PB({arr[i].F, arr[n-1].F});
                l1 -= arr[i].S;
            }else{
                brr.PB({arr[i].F, arr[n-2].F});
                l2 -= arr[i].S;
            }
        }
        brr.PB({arr[n-1].F, arr[n-2].F});

        cout << brr.size() << endl;
        for(auto& i: brr){
            cout << i.F << ' ' << i.S << endl;
        }
        return;

        // vector<pair<int,int>>brr;
        // int l = 0;
        // FOR(r, 1, n){
        //     arr[l].S -= arr[r].S;
        //     brr.PB({arr[l].F, arr[r].F});
        //     if(arr[l].S<=0){
        //         l = r+1;
        //         r++;
        //     }
        // }
        // // if(arr[n-1].S>0){
        // //     cout << -1 << endl;
        // // }else{
        // cout << brr.size() << endl;
        // for(auto& i: brr){
        //     cout << i.S << ' ' << i.F << endl;
        // }
        // // }
        // return;
    }

    if(m*2>n){
        cout << -1 << endl;
        return;
    }

    sort(ALL(arr), [&](pair<int,int>p1, pair<int,int>p2) -> bool {
        return p1.S < p2.S;
    });

    vector<pair<int,int>>brr;
    FOR(i, 0, n-2*m){
        brr.PB({arr[i].F, arr[i+1].F});
    }

    FOR(i, 0, m){
        int x = (n-2*m) + i;
        int y = (n-m) + i;
        brr.PB({arr[x].F, arr[y].F});
    }

    cout << brr.size() << endl;
    for(auto& i: brr){
        cout << i.S << ' ' << i.F << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
