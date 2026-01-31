// ==================================================
// Problem   : 533277I - Unknown
// URL       : https://codeforces.com/contest/533277/problem/I
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
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");

    int n;
    fcin >> n;
    int k = 3;

    int bottles[3] = {1, 5, 6};

    vector < int > dp(n+1, INT_MAX);
    dp[0] = 0;

    vector < int > last_bottles(n+1, 0);
    FOR(i, 1, n+1){
        for(int j: bottles){
            if(dp[i-j]+1<dp[i] and i-j>=0 and dp[i-j]!=INT_MAX){
                dp[i] = dp[i-j] + 1;
                last_bottles[i] = j;
            }
        }
    }

    // print(dp);
    // print(last_bottles);

    if(dp[n]==INT_MAX){
        fcout << -1 << endl;
    }else{
        fcout << dp[n] << endl;

        vector < int > ans;
        int nn = n;
        while(nn>0){
            int l = last_bottles[nn];
            ans.PB(l);
            nn -= l;
        }

        sort(ALL(ans));
        // print(ans);
        for(int i: ans){
            fcout << i << ' ';
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
