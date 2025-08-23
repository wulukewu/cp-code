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
    int n;
    cin >> n;

    vector < vector < int > > arr(n, vector < int > (n));
    FOR(i, 0, n){
        FOR(j, 0, n){
            cin >> arr[i][j];
        }
    }

    int offs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector < vector < pair < int, int > > > dist(n, vector < pair < int, int > > (n, {INT_MAX, INT_MAX}));
    dist[0][0] = {0, 0};

    int a, b;
    // int ans1 = -1;
    // int ans2 = -1;
    // prior < pair < pair < int, int >, pair < int, int > > > pq;
    queue < pair < pair < int, int >, pair < int, int > > > pq;
    pq.push({{0, 0}, {0, 0}});
    while(!pq.empty()){
        auto t = pq.front();
        // cout << t.F.F << ' ' << t.F.S << ' ' << t.S.F << ' ' << t.S.S << endl;
        pq.pop();

        int r = t.S.F;
        int c = t.S.S;

        if(t.F.F>dist[r][c].F or (t.F.F==dist[r][c].F and t.F.S>dist[r][c].S)){
            continue;
        }
        
        // if(r==n-1 and c==n-1){
        //     ans1 = t.F.F;
        //     ans2 = t.F.S;
        //     // break;
        // }

        FOR(k, 0, 4){
            int x = r + offs[k][0];
            int y = c + offs[k][1];
            if(!(x>=0 and x<n and y>=0 and y<n)) continue;

            a = abs(arr[x][y]-arr[r][c]);
            a = max(t.F.F, a);
            b = t.F.S + 1;
            if(a<dist[x][y].F or (a==dist[x][y].F and b<dist[x][y].S)){
                dist[x][y] = {a, b};
                pq.push({{a, b}, {x, y}});
            }
        }
    }

    // cout << ans1 << endl << ans2 << endl;
    cout << dist[n-1][n-1].F << endl << dist[n-1][n-1].S << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
