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

void solve(){
    int n;
    cin >> n;
    vector< vector< vector<int> > > v(n , vector< vector<int> >(n , vector<int>(n,0)));

    int k = n*n;
    vector< vector<int> > inpu(k, vector<int>(n));
    FOR(idx,0,k){
        cin >> inpu[idx][0] >> inpu[idx][1] >> inpu[idx][2];
        // print(inpu[idx]);
        // cout << endl;
    }
    int sum = 0;
    FOR(x,0,n){
        FOR(y,0,n){
            // cout << x << " " << y << endl;
            int line = x*(n-1) + y;
            FOR(z,0,n){
                v[x][y][z] = inpu[line][z];
                sum += v[x][y][z];
            }
            // print(cube[x][y]);
            // cout << endl;
        }
    }

    // vector<bool>vx(n, false);
    // vector<bool>vy(n, false);
    // vector<bool>vz(n, false);
    set<int>sx, sy, sz;
    FOR(i, 0, n){
        sx.insert(i);
        sy.insert(i);
        sz.insert(i);
    }
    int ans = sum;
    auto dfs = [&](auto&& self, int c) -> void {
        if(sx.empty()){
            ans = min(ans, c);
            return;
        }
        for(int x: sx){
            for(int y: sy){
                for(int z: sz){
                    sx.erase(x);
                    sy.erase(y);
                    sz.erase(z);
                    self(self, c+v[x][y][z]);
                    sx.insert(x);
                    sy.insert(y);
                    sz.insert(z);
                }
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}