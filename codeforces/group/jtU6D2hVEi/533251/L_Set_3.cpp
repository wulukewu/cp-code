// ==================================================
// Problem   : jtU6D2hVEiL - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/L
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
    int n;
    cin >> n;

    set < int > s;
    string op;
    int x;
    FOR(i, 0, n){
        cin >> op >> x;
        if(op=="add"){
            if(s.find(x)==s.end()){
                s.insert(x);
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(op=="remove"){
            if(s.find(x)!=s.end()){
                s.erase(x);
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(op=="nearest"){
            if(s.empty()){
                cout << "ERROR" << endl;
                continue;
            }

            auto it = s.lower_bound(x);
            // cout << *it << endl;
            
            int y = 0;
            int z = LLONG_MAX;
            if(it!=s.end()){
                if(abs(*it-x)<z){
                    y = *it;
                    z = abs(*it-x);
                }else if(abs(*it-x)==z){
                    y = max(y, *it);
                }
            }
            if(it!=s.begin()){
                it--;
                if(abs(*it-x)<z){
                    y = *it;
                    z = abs(*it-x);
                }else if(abs(*it-x)==z){
                    y = max(y, *it);
                }
            }
            cout << y << endl;
        }
    }

    stack < int > ans;
    for(int i: s){
        ans.push(i);
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
