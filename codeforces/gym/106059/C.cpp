// ==================================================
// Problem   : 106059C.cpp - Unknown
// URL       : https://codeforces.com/contest/106059/problem/C.cpp
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
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1;; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    vector < vector < int > > v(2, vector < int > (6));
    FOR(i, 0, 6) cin >> v[0][i];
    FOR(i, 0, 6) cin >> v[1][i];

    // FOR(i, 0, 2) print(v[i]);
    // return;

    int ans = false;
    double ans_cos;
    int x1, y1, x2, y2, x3, y3;
    FOR(i, 0, 2){
        FOR(j, 0, 2){
            FOR(k, 0, 2){
                x1 = v[i][0];
                y1 = v[i][1];
                x2 = v[j][2];
                y2 = v[j][3];
                x3 = v[k][4];
                y3 = v[k][5];
                cout << x1 << y1 << x2 << y2 << x3 << y3 << endl;

                int ux = x1 - x2;
                int uy = y1 - y2;
                int vx = x3 - x2;
                int vy = y3 - y2;
                // cout << ux << ' ' << uy << ' ' << vx << ' ' << vy << endl;
                int uv = ux * vx + uy * vy;
                int ul = ux*ux + uy*uy;
                double ull = sqrt(ul);
                int vl = vx*vx + vy*vy;
                double vll = sqrt(vl);
                // cout << uv << ' ' << ul << ' ' << vl << endl;
                double cos = uv / ull / vll;
                // cout << cos << endl;
                cout << fixed << setprecision(4) << cos << endl;

                if(i==0 and j==0 and k==0){
                    ans_cos = cos;
                }else{
                    if(cos==ans_cos){
                        ans = true;
                        break;
                    }
                }
            }
            if(ans) break;
        }
        if(ans) break;
    }
    
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}