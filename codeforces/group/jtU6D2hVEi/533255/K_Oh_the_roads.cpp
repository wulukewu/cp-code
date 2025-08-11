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
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve() {
    ifstream fcin("roads.in");
    ofstream fcout("roads.out");

    int n, m;
    fcin >> n >> m;
    // cin >> n >> m;
    vector<vector<int>> G(n+1);

    while(m--){
        int u, v;
        fcin >> u >> v;
        // cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<bool> visited(n+1, false);
    vector<pair<int, int> > result;

    auto dfs = [&](auto&& self, int u) -> void {
        visited[u] = true;
        for(auto v : G[u]){
            if(!visited[v]){
                result.emplace_back(u, v);
                self(self, v);
            }
        }
    };

    FOR(i, 1, n+1){
        if(!visited[i]){
            dfs(dfs, i);
        }
    }

    fcout << result.size() << endl;
    // cout << result.size() << endl;

    for (auto i : result) {
        fcout << i.F << ' ' << i.S << endl;
        // cout << i.F << ' ' << i.S << endl;
    }


}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
