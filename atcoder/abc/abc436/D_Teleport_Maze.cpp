// ==================================================
// Problem   : ABC436_D - Teleport Maze
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc436/tasks/abc436_d
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
    int h, w;
    cin >> h >> w;

    vector<vector<pair<int, int>>>mp(26);

    vector<vector<char>>v(h, vector<char>(w));
    FOR(i, 0, h){
        FOR(j, 0, w){
            cin >> v[i][j];
            if(v[i][j]!='.' and v[i][j]!='#'){
                mp[v[i][j]-'a'].PB({i, j});
            }
        }
    }

    // map<pair<int, int>, pair<int, int>>mp2;
    // for(auto i: mp){
    //     // for(auto j: i.S){
    //     //     cout << i.F << ' ' << j.F << ' ' << j.S << endl;
    //     // }
    //     mp2[i.S[0]] = i.S[1];
    //     mp2[i.S[1]] = i.S[0];
    // }

    int offs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>>visit(h, vector<bool>(w, false));
    vector<bool>visitchar(26, false);

    int ans = -1;
    queue<pair<int, pair<int, int>>>q;
    q.push({0, {0, 0}});
    visit[0][0] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int step = t.F;
        int &x = t.S.F;
        int &y = t.S.S;
        // cout << step << ' ' << x << ' ' << y << endl;
        if(x==h-1 and y==w-1){
            ans = step;
            break;
        }
        // if(visit[x][y]) continue;
        // else visit[x][y] = true;

        if(v[x][y]!='.' and v[x][y]!='#'){
            // auto tar = mp2[{x, y}];
            // visit[tar.F][tar.S] = true;
            // q.push({step+1, {tar.F, tar.S}});
            if(!visitchar[v[x][y]-'a']){
                for(auto i: mp[v[x][y]-'a']){
                    // cout << i.F << ' ' << i.S << endl;
                    if(!visit[i.F][i.S]){
                        q.push({step+1, {i.F, i.S}});
                    }
                }
                visitchar[v[x][y]-'a'] = true;
            }
        }

        FOR(k, 0, 4){
            int r = x + offs[k][0];
            int c = y + offs[k][1];
            if(!(r>=0 and r<h and c>=0 and c<w)) continue;
            // cout << r << ' ' << c << endl;
            // if(visit[r][c]) continue;

            if(v[r][c]!='#'){
                if(!visit[r][c]){
                    q.push({step+1, {r, c}});
                    visit[r][c] = true;
                }
            }
            // else if(v[r][c]=='#'){
            //     continue;
            // }else{
            //     visit[r][c] = true;
            //     q.push({step+1, {r, c}});
            //     auto tar = mp2[{r, c}];
            //     visit[tar.F][tar.S] = true;
            //     q.push({step+2, {tar.F, tar.S}});
            // }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
