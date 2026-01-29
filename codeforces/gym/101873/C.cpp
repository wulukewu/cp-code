// ==================================================
// Problem   : 101873C - Unknown
// URL       : https://codeforces.com/contest/101873/problem/C
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T> >;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << " ";
    }
    cout << endl;
}

void solve(){
    int x,n,m,t;
    cin >> x;
    cin >> n >> m >> t;
    vector <vector<int>> path(n+1,vector<int>());
    int a,b;
    FOR(i,0,m){
        cin >> a >> b;
        path[a-1].push_back(b-1);
        path[b-1].push_back(a-1);
    }
    vector< pair<int,int> > ride(n);
    FOR(i,0,n){
        cin >> ride[i].F >> ride[i].S;
    }

    vector < vector < int > > dp(x+1, vector < int > (n, INT_MAX));
    if(ride[0].F <= x){
        dp[ride[0].F][0] = ride[0].S;
    }
    FOR(i, 0, x+1){
        FOR(j, 0, n){
            if(dp[i][j] == INT_MAX) continue;
            // print(path[j]);
            for(int k: path[j]){
                // if(i+ride[k-1].F+t<=x){
                //     int val = dp[i][j] + ride[k].S;
                //     dp[i+ride[k].F+t][k] = min(dp[i+ride[k-1].F+t][k], val);
                // }

                int nt = i + t + ride[k].F;
                if(nt <= x){
                    int val = dp[i][j] + ride[k].S;
                    dp[nt][k] = min(dp[nt][k], val);
                }
            }
            if(i+ride[j].F<=x){
                dp[i+ride[j].F][j] = min(dp[i+ride[j].F][j], dp[i][j]+ride[j].S);
            }
        }
    }

    // FOR(i, 0, x+1){
    //     print(dp[i]);
    // }

    if(dp[x][0]!=INT_MAX){
        cout << dp[x][0] << endl;
    }else{
        cout << "It is a trap." << endl;
    }

    // vector <vector<int>> dp(x+1,vector<int>(n+1,-1));
    // dp[0][1] = 0;
    // dp[ride[1].F][1] = ride[1].S;
    // FOR(i,ride[1].F,x+1){
    //     FOR(j,1,n+1){
    //         if(dp[i][j] != -1){
    //             FOR(k,)
    //         }
    //     }
    // }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

