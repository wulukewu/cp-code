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
// const double EPS = 1e-9;
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
    int t;
    cin >> t;

    FOR(tt, 1, t+1){
        int n;
        cin >> n;

        vector < int > v(n);
        FOR(i, 0, n) cin >> v[i];
        
        int l = 1, r = 1e9;
        int m;
        while(l<r){
            m = l + (r-l)/2;
            // cout << "m: " << m << endl;

            int cnt = 0;
            vector < bool > vis(n, false);
            queue < int > q;

            FOR(i, 0, n){
                if(v[i]<=m){
                    q.push(i);
                    vis[i] = true;
                    cnt++;
                }
            }

            while(!q.empty()){
                int x = q.front();
                q.pop();

                if(x-1>=0){
                    if(abs(v[x-1]-v[x])<=m and !vis[x-1]){
                        q.push(x-1);
                        vis[x-1] = true;
                        cnt++;
                    }
                }
                if(x+1<n){
                    if(abs(v[x+1]-v[x])<=m and !vis[x+1]){
                        q.push(x+1);
                        vis[x+1] = true;
                        cnt++;
                    }
                }
            }

            // cout << m << ' ' << cnt << endl;

            if(cnt==n){
                r = m;
            }else{
                l = m + 1;
            }
        }

        // cout << l << ' ' << r << ' ' << m << endl;
        cout << "Case #" << tt << ": " << r << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
