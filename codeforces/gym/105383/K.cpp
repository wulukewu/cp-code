/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105383K — Kingdom's Development Plan
 * Problem URL:    https://codeforces.com/gym/105383/problem/K
 *
 * Matched result: AC
 * Submission:     #339441707
 * Submission URL: https://codeforces.com/gym/105383/submission/339441707
 * Submitted:      2025-09-20 07:45:41 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        187 ms
 * Memory:         2.4 MiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-09-20 13:03:16 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define endl '\n'
//#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector < vector < int > > G(n);
    vector < int > unlock(n, 0);
    int u, v;
    FOR(i, 0, m){
        cin >> u >> v;
        u--; v--;
        G[u].PB(v);
        unlock[v]++;
    }

    vector < bool > visit(n, false);
    vector < int > ans;
    prior < int > q;
    FOR(i, 0, n){
        if(unlock[i]==0){
            q.push(i);
            // visit[i] = true;
            // ans.PB(i);
        }
    }

    while(!q.empty()){
        int x = q.top();
        q.pop();
        // cout << x << endl;
        
        visit[x] = true;
        ans.PB(x);

        for(int y: G[x]){
            unlock[y]--;
            if(unlock[y]==0){
                q.push(y);
                // visit[y] = true;
                // ans.PB(y);
            }
        }
    }

    if(ans.size()==n){
        for(int i: ans){
            cout << i+1 << ' ';
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
