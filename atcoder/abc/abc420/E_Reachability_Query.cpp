// ==================================================
// Problem   : ABC420_E - Reachability Query
// Limits    : 3 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc420/tasks/abc420_e
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
    int n, q;
    cin >> n >> q;

    vector < int > root(n);
    FOR(i, 0, n) root[i] = i;
    vector < bool > color(n, false);
    vector < int > black(n, 0);

    auto find_root = [&](auto&& self, int x) -> int {
        if(root[x]==x){
            return x;
        }else{
            int r = self(self, root[x]);
            root[x] = r;
            return r;
            // return self(self, root[x]);
        }
    };

    auto merge = [&](int x, int y) -> void {
        x = find_root(find_root, x);
        y = find_root(find_root, y);
        if(x==y) return;
        root[y] = root[x];
        black[x] += black[y];
        black[y] = 0;
    };

    int type, u, v;
    while(q--){
        cin >> type;
        if(type==1){
            cin >> u >> v;
            u--; v--;
            merge(u, v);
        }else if(type==2){
            cin >> v;
            v--;
            int r = find_root(find_root, v);
            if(color[v]){
                black[r]--;
            }else{
                black[r]++;
            }
            color[v] = !color[v];
        }else{
            cin >> v;
            v--;
            int r = find_root(find_root, v);
            // if(black[r]){
            //     cout << "Yes" << endl;
            // }else{
            //     cout << "No" << endl;
            // }
            cout << (black[r]>0 ? "Yes" : "No") << endl;
        }

        // print(root);
        // print(color);
        // print(black);
        // cout << '-' << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
