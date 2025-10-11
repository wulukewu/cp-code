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
    int h, w;
    cin >> h >> w;

    vector < vector < char > > arr(h, vector < char > (w));
    int x, y;
    int xl=INT_MAX, yl=INT_MAX;
    int xr=-1, yr=-1;
    string s;
    FOR(i, 0, h){
        cin >> s;
        FOR(j, 0, w){
            arr[i][j] = s[j];
            if(arr[i][j]=='T'){
                x = i;
                y = j;
            } else if(arr[i][j]=='#'){
                xl = min(xl, i);
                yl = min(yl, j);
                xr = max(xr, i);
                yr = max(yr, j);
            }
        }
    }

    // cout << x << ' ' << y << ' ' << xl << ' ' << xr << ' ' << yl << ' ' << yr << endl;

    int offs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector < vector < bool > > visit(h, vector < bool > (w, false));

    queue < pair < int, pair < int, int > > > q;
    q.push({0, {x, y}});

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        int st = t.F;
        int xc = t.S.F;
        int yc = t.S.S;
        if((xc==xl or xc==xr) and (yc==yl or yc==yr)){
            cout << st+1 << endl;
            return;
        }

        FOR(i, 0, 4){
            int r = xc + offs[i][0];
            int c = yc + offs[i][1];
            if(!(0<=r and r<h and 0<=c and c<w)) continue;
            if(arr[r][c]=='#') continue;
            if(visit[r][c]) continue;

            visit[r][c] = true;
            q.push({st+1, {r, c}});
        }
    }

    cout << -1 << endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
