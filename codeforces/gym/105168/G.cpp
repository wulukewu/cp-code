// ==================================================
// Problem   : 105168G - Unknown
// URL       : https://codeforces.com/contest/105168/problem/G
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
// #define float double
// #define float long double
#define FOR(i, a ,b) for(int i = a; i< b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve(){
    int n;
    cin >> n;
    
    vector < vector < int > > G(n+1);
    int u, v;
    FOR(i, 0, n-1){
        cin >> u >> v;
        G[u].PB(v);
        // G[v].PB(u);
    }

    queue < set < int > > q;
    set < int > s;
    set < int > ss;
    s.insert(1);
    q.push(s);
    vector < bool > visit(n+1, false);
    int ans = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        // for(int i: t){
        //     cout << i << ' ';
        // }
        // cout << endl;

        if(t.empty()){
            ans++;
            ans %= 998244353;
            continue;
        }

        for(int i: t){
            s = t;
            s.erase(i);
            // visit[i] = true;
            for(int j: G[i]){
                // if(visit[j]) continue;
                s.insert(j);
            }
            q.push(s);
        }
    }
    
    // print(visit);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}