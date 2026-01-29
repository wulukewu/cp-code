// ==================================================
// Problem   : ABC428_C - Brackets Stack Query
// Limits    : 3 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc428/tasks/abc428_c
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
    int q;
    cin >> q;

    vector < pair < int, int > > v;
    v.PB({0, 0});

    FOR(i, 0, q){
        int x;
        cin >> x;
        if(x==1){
            char c;
            cin >> c;
            auto [a, b] = v.back();
            // cout << a << ' ' << b << endl;
            if(c=='('){
                a++;
            }else{
                a--;
            }
            b = min(b, a);
            v.PB({a, b});
        }else{
            v.pop_back();
        }
        
        auto [a, b] = v.back();
        if(a==0 and b>=0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    // stack < pair < char, int > > st;
    // stack < pair < char, int > > st2;
    // vector < pair < char, int > > v;

    // int idx = 0;
    // FOR(i, 0, q){
    //     int x;
    //     cin >> x;
    //     if(x==1){
    //         char c;
    //         cin >> c;
    //         v.PB({c, -1});
    //         if(c=='('){
    //             st.push({'(', idx});
    //         }else{
    //             if(!st.empty() and st.top().F=='('){
    //                 v[idx].S = st.top().S;
    //                 st.pop();
    //             }else{
    //                 st.push({')', idx});
    //             }
    //         }
    //         idx++;
    //     }else{
    //         int k = v[idx-1].S;
    //         FOR(j, k, idx-1){
    //             st.push(v[j]);
    //         }
    //     }

    //     while(!st.empty()){
    //         auto t = st.top();
    //         st.pop();
    //         cout << t.F << ' ' << t.S << endl;
    //         st2.push(t);
    //     }
    //     while(!st2.empty()){
    //         auto t = st2.top();
    //         st2.pop();
    //         st.push(t);
    //     }
    //     cout << '-' << endl;
    // }
    // FOR(j, 0, idx){
    //     cout << v[j].F << ' ' << v[j].S << endl;
    // }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
