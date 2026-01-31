// ==================================================
// Problem   : 533280I - Unknown
// URL       : https://codeforces.com/contest/533280/problem/I
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
    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.size();
    int l2 = s2.size();

    vector < vector < int > > dp(l1+1, vector < int > (l2+1, 0));
    FOR(i, 0, l1+1) dp[i][l2] = l1-i;
    FOR(j, 0, l2+1) dp[l1][j] = l2-j;

    for(int i=l1-1; i>=0; i--){
        for(int j=l2-1; j>=0; j--){
            if(s1[i]==s2[j]){
                dp[i][j] = dp[i+1][j+1];
            }else{
                int val = min(dp[i+1][j], dp[i][j+1]);
                val = min(val, dp[i+1][j+1]);
                dp[i][j] = val + 1;
            }
        }
    }

    // FOR(i, 0, l1+1){
    //     print(dp[i]);
    // }

    cout << dp[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
