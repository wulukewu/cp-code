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

    vector < string > arr(h);
    FOR(i, 0, h) cin >> arr[i];

    pair < int, int > start = {-1, -1};
    pair < int, int > goal = {-1, -1};

    FOR(i, 0, h){
        FOR(j, 0, w){
            if(arr[i][j]=='S'){
                start = {i, j};
            }else if(arr[i][j]=='G'){
                goal = {i, j};
            }
        }
    }

    int offs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector < vector < bool > > visit0(h, vector < bool > (w, false));
    vector < vector < bool > > visit1(h, vector < bool > (w, false));

    queue < pair < pair < bool, int >, pair < int, int > > > q;
    q.push({{true, 0}, start});

    int ans = INT_MAX;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        bool door = t.F.F;
        int step = t.F.S;
        int r = t.S.F;
        int c = t.S.S;
        // cout << t.F.F << ' ' << t.F.S << ' ' << t.S.F << ' ' << t.S.S << endl;
        // cout << door << ' ' << step << ' ' << r << ' ' << c << endl;

        if(r==goal.F and c==goal.S){
            ans = min(ans, step);
            continue;
        }

        FOR(k, 0, 4){
            int x = r + offs[k][0];
            int y = c + offs[k][1];
            if(!(x>=0 and x<h and y>=0 and y<w)) continue;

            if(arr[x][y]=='#') continue;
            else if((visit0[x][y] and door) or (visit1[x][y] and !door)) continue;
            else if((arr[x][y]=='x' and door) or (arr[x][y]=='o' and !door)) continue;

            if(door) visit0[x][y] = true;
            else visit1[x][y] = true;

            if(arr[x][y]=='?') door = !door;
            q.push({{door, step+1}, {x, y}});
            if(arr[x][y]=='?') door = !door;
        }
    }

    if(ans==INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }


    // bool door = true;
    // int offs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // // vector < vector < bool > > visit0(h, vector < bool > (w, false));
    // // vector < vector < bool > > visit1(h, vector < bool > (w, false));
    // vector < vector < int > > dist0(h, vector < int > (w, INT_MAX));
    // vector < vector < int > > dist1(h, vector < int > (w, INT_MAX));

    // int ans = INT_MAX;
    // auto dfs = [&](auto&& self, int r, int c, int step) -> void {
    //     // cout << "now: " << r << ' ' << c << endl;

    //     if(r==goal.F and c==goal.S){
    //         // cout << "return " << step << endl;
    //         ans = min(ans, step);
    //         return;
    //     }

    //     FOR(k, 0, 4){
    //         int x = r + offs[k][0];
    //         int y = c + offs[k][1];
    //         // cout << x <<  ' ' << y << endl;
    //         if(!(x>=0 and x<h and y>=0 and y<w)) continue;

    //         if(arr[x][y]=='#') continue;
    //         // else if((visit0[x][y] and door) or (visit1[x][y] and !door)) continue;
    //         else if((dist0[x][y]<=step+1 and door) or (dist1[x][y]<=step+1 and !door)) continue;
    //         else if((arr[x][y]=='x' and door) or (arr[x][y]=='o' and !door)) continue;
            
    //         // if(door) visit0[x][y] = true;
    //         // else visit1[x][y] = true;
    //         if(door) dist0[x][y] = step+1;
    //         else dist1[x][y] = step+1;

    //         if(arr[x][y]=='?') door = !door;
    //         self(self, x, y, step+1);
    //         if(arr[x][y]=='?') door = !door;
    //     }
    // };

    // dfs(dfs, start.F, start.S, 0);

    // if(ans==INT_MAX){
    //     cout << -1 << endl;
    // }else{
    //     cout << ans << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
