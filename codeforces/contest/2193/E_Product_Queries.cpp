// ==================================================
// Problem   : 2193E - Product Queries
// Tags      : dp, math, number theory, shortest paths
// Runtime   : 281 ms
// Memory    : 20700 KB
// URL       : https://codeforces.com/contest/2193/problem/E
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
    int n;
    cin >> n;

    set<int>st;
    FOR(i, 0, n){
        int a;
        cin >> a;
        st.insert(a);
    }

    bool has1 = false;
    vector<int>arr;
    for(int i: st){
        if(i==1) has1 = true;
        arr.PB(i);
    }
    // reverse(ALL(arr));
    // print(arr);

    vector<int>dist(n+1, -1);
    queue<int>q;

    for(int i: arr){
        if(i>1 and i<=n){
            dist[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int i: arr){
            if(i==1) continue;
            int x = t * i;
            if(x>n) break;
            if(x<=n and dist[x]==-1){
                dist[x] = dist[t] + 1;
                q.push(x);
            }
        }
    }

    // print(dist);

    FOR(i, 1, n+1){
        if(i==1){
            if(has1){
                cout << 1 << ' ';
            }else{
                cout << -1 << ' ';
            }
        }else{
            cout << dist[i] << ' ';
        }
    }
    cout << endl;

    // FOR(i, 1, n+1){
    //     int num = i;
    //     int cnt = 0;
    //     for(int j: arr){
    //         if(j==1) continue;
    //         while(num%j==0){
    //             num /= j;
    //             cnt++;
    //         }
    //     }

    //     if(i==1 and has1){
    //         cout << 1 << ' ';
    //         continue;
    //     }
    //     if(cnt>0){
    //         if(num==1){
    //             cout << cnt << ' ';
    //         }else{
    //             cout << -1 << ' ';
    //         }
    //     }else{
    //         // if(has1){
    //         //     cout << 1 << ' ';
    //         // }else{
    //         //     cout << -1 << ' ';
    //         // }
    //         cout << -1 << ' ';
    //     }
    // }
    // cout << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
