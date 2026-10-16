#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define ing long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

using uint = unsigned;
using ull = unsigned int long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;
const double EPS = 1e-9;

vector<int> find_cycle_directed(int n, vector<vector<int>>G){
    vector<int> visit(n, 0);
    vector<int> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    auto dfs = [&](auto&& self, int x) -> bool {
        visit[x] = 1;
        for(int y: G[x]){
            if(visit[y] == 1){
                cycle_start = y;
                cycle_end = x;
                return true;
            }

            if(visit[y] == 0){
                parent[y] = x;
                if(self(self, y)) return true;
            }
        }
        visit[x] = 2;
        return false;
    };

    FOR(i, 0, n){
        if(visit[i] == 0 && dfs(dfs, i)) break;
    }

    vector<int> cycle;
    if(cycle_start != -1){
        int x = cycle_end;
        while (x != cycle_start){
            cycle.PB(x);
            x = parent[x];
        }
        cycle.PB(cycle_start);
        reverse(ALL(cycle));
    }
    return cycle;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>>G(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> G[i][j];
        }
    }

    auto s = find_cycle_directed(n, G);
    print(s);
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}