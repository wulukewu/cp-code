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

    vector<vector<int>>G(n);
    int u, v;
    FOR(i, 0, n-1){
        cin >> u >> v;
        G[u-1].PB(v-1);
        G[v-1].PB(u-1);
    }

    vector<int>dep(n, 0);
    vector<int>child(n, 0);
    vector<bool>visit(n, false);

    queue<pair<int, int>>q;
    visit[0] = true;
    q.push({0, 0});

    int ans1 = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = t.F;
        int d = t.S;

        dep[d]++;
        ans1 = max(ans1, dep[d]);

        int cnt = 0;
        for(auto y: G[x]){
            if(!visit[y]){
                visit[y] = true;
                q.push({y, d+1});
                cnt++;
            }
        }
        child[x] = cnt;
    }
    // cout << ans1 << endl;

    int ans2 = 0;
    FOR(i, 0, n){
        ans2 = max(ans2, child[i]+1);
    }
    // cout << ans2 << endl;

    int ans = max(ans1, ans2);
    cout << ans << endl;


    // vector<bool>color(n, false);
    // int cnt = 0;
    // FOR(i, 0, n){
    //     if(color[i]) continue;

    //     queue<int>q;
    //     q.push(i);
    //     color[i] = true;
    //     while(!q.empty()){
    //         int t = q.front();
    //         q.pop();

    //         for(int i: G[t]){
    //             for(int j: G[i]){
    //                 while(color[j]){
                        
    //                 }
    //             }
    //         }
    //     }
    //     cnt++;
    // }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
