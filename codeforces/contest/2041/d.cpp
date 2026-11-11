#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

// struct dir {
//     int left, right, up, down;
// };

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string>v(n);
    int sx, sy, tx, ty;
    FOR(i, 0, n){
        cin >> v[i];
        FOR(j, 0, m){
            if(v[i][j]=='S'){
                sx = i, sy = j;
            }else if(v[i][j]=='T'){
                tx = i, ty = j;
            }
        }
    }

    vector<vector<int>>vis(n, vector<int>(m, -1));
    int offs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    auto dfs = [&](auto&& self, int x, int y, int step, pair<int, int> d) -> void {
        // cout << x << ' ' << y << ' ' << step << ' ' << d.F << ' ' << d.S << endl;
        if(vis[x][y]!=-1 && vis[x][y]<step) return;
        vis[x][y] = step;
        if(v[x][y]=='T'){
            // cout << step << endl;
            return;
        }

        FOR(k, 0, 4){
            // if(d.S==3) continue;
            int r = x+offs[k][0];
            int c = y+offs[k][1];
            if(!(0<=r && r<n && 0<=c && c<m)) continue;
            if(v[r][c]=='#') continue;
            if(d.F==k && d.S==3){
                // self(self, r, c, step+3, {k, 1});
                bool det = false;
                if(k==0 || k==1){
                    for(int x2: {x-1, x+1}){
                        if(!(0<=x2 && x2<n && 0<=y && y<m)) continue;
                        if(v[x2][y]=='#') continue;
                        det = true;
                    }
                }else if(k==2 || k==3){
                    for(int y2: {y-1, y+1}){
                        if(!(0<=x && x<n && 0<=y2 && y2<m)) continue;
                        if(v[x][y2]=='#') continue;
                        det = true;
                    }
                }
                if(det){
                    // cout << "t2: ";
                    self(self, r, c, step+3, {k, 1});
                }else{
                    // cout << "t3: ";
                    self(self, r, c, step+3, {k, 2});
                }
            }else{
                // cout << "t1: ";
                self(self, r, c, step+1, {k, (d.F==k ? d.S : 0)+1});
            }
        }
    };
    vis[sx][sy] = 0;
    dfs(dfs, sx, sy, 0, {0, 0});
    // FOR(i, 0, n) print(vis[i]);
    cout << vis[tx][ty] << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}