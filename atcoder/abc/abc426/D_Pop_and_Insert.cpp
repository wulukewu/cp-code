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
    string s;
    cin >> n >> s;

    vector < pair < char, int > > v;
    v.PB({s[0], 1});
    FOR(i, 1, n){
        if(s[i]==s[i-1]){
            v[v.size()-1].S++;
        }else{
            v.PB({s[i], 1});
        }
    }

    // for(auto i: v){
    //     cout << i.F << ' ' << i.S << endl;
    // }

    // to 0
    int ans0 = 0;
    int m0 = 0;
    for(auto i: v){
        if(i.F=='0'){
            ans0 += i.S * 2;
            m0 = max(m0, i.S);
        }else{
            ans0 += i.S;
        }
    }
    ans0 -= m0 * 2;
    
    // to 1
    int ans1 = 0;
    int m1 = 0;
    for(auto i: v){
        if(i.F=='1'){
            ans1 += i.S * 2;
            m1 = max(m1, i.S);
        }else{
            ans1 += i.S;
        }
    }
    ans1 -= m1 * 2;

    int ans = min(ans0, ans1);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
