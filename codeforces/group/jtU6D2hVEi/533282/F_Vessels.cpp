// ==================================================
// Problem   : jtU6D2hVEiF - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/F
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

    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];
    vector < int > brr(n, 0);

    vector < int > boss(n+1);
    FOR(i, 0, n+1) boss[i] = i;

    auto find_root = [&](auto&& self, int x) -> int {
        if(boss[x]==x) return x;

        int root = self(self, boss[x]);
        boss[x] = root;
        return root;
    };

    // auto connect = [&](int x, int y) -> void {
    //     int root_x = find_root(find_root, x);
    //     int root_y = find_root(find_root, y);
    //     if(root_x != root_y){
    //         boss[root_x] = boss[root_y];
    //     }
    // };

    // auto fill = [&](auto&& self, int x, int p) -> void {
    //     x -= arr[p];
    //     arr[p] = 0;
    //     int root = find_root(find_root, p);
    //     connect(p, root);
    //     if(x>0){
    //         self(self, x, root);
    //     }
    // };

    int m;
    cin >> m;

    int q, p, x, k;
    FOR(i, 0, m){
        cin >> q;
        if(q==1){
            cin >> p >> x;
            p--;

            while(x>0){
                p = find_root(find_root, p);
                if(p>=n) break;

                int avil = arr[p]-brr[p];
                if(avil>=x){
                    brr[p] += x;
                    x = 0;
                }else{
                    x -= avil;
                    brr[p] = arr[p];
                    boss[p] = find_root(find_root, p+1);
                }
                // if(arr[p]>=x){
                //     arr[p] -= x;
                //     x = 0;
                // }else{
                //     x -= arr[p];
                //     arr[p] = 0;
                //     boss[p] = boss[find_root(find_root, p+1)];
                // }
            }

            // if(arr[p]==0){

            // }else if(arr[p]>x){
            //     arr[p] -= x;
            // }else{
            //     // fill(fill, x, p);
            // }
        }else if(q==2){
            cin >> k;
            cout << brr[k-1] << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
