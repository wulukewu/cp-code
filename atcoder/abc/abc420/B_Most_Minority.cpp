// ==================================================
// Problem   : ABC420_B - Most Minority
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc420/tasks/abc420_b
// ==================================================

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
    int n, m;
    cin >> n >> m;

    vector < string > v(n);
    FOR(i, 0, n){
        cin >> v[i];
    }

    vector < int > s(n, 0);
    FOR(i, 0, m){
        int v0 = 0;
        int v1 = 0;
        FOR(j, 0, n){
            if(v[j][i]=='0') v0++;
            else v1++;
        }
        bool p0 = v0==0 or v1==0 or v0<v1;
        bool p1 = v0==0 or v1==0 or v0>v1;
        FOR(j, 0, n){
            if(v[j][i]=='0' and p0){
                s[j]++;
            }else if(v[j][i]=='1' and p1){
                s[j]++;
            }
        }
    }

    // print(s);
    int max_score = 0;
    FOR(i, 0, n){
        max_score = max(max_score, s[i]);
    }

    FOR(i, 0, n){
        if(s[i]==max_score){
            cout << i+1 << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
