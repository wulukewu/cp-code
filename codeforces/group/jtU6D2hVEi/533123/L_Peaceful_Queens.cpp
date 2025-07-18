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

void solve() {
    int n;
    cin >> n;

    vector < vector < int > > ans;

    vector < bool > visit(n, false);
    vector < bool > diag_pos(n, false);
    vector < bool > diag_neg(n, false);
    auto dfs = [&](vector < int > v, auto&& self) -> void {
        int m = v.size();
        if(m==n){
            ans.push_back(v);
            return;
        }

        FOR(i, 0, n){
            if(!visit[i] and !diag_pos[m-i+n-1] and !diag_neg[m+i]){
                v.push_back(i);
                visit[i] = true;
                diag_pos[m-i+n-1] = true;
                diag_neg[m+i] = true;
                self(v, self);
                v.pop_back();
                visit[i] = false;
                diag_pos[m-i+n-1] = false;
                diag_neg[m+i] = false;
            }
        }
    };

    dfs(vector < int >(), dfs);

    for(auto i: ans){
        cout << "(";
        FOR(j, 0, n){
            cout << i[j]+1;
            if(j<n-1){
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
