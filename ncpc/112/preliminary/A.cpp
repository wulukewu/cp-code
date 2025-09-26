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
void addmod(ll &a, ll b){a = (a+b)%MOD;}
void submod(ll &a, ll b){a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b){a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}

template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

int linef(int x1, int y1, int x2, int y2, int x, int y){
    return (y1-y2)*x + (x2 - x1)*y + (y2-x1 - x2y1)
}

bool isintersect(int line1x1, int line1y1, int line1x2, int line1y2, int line2x1, int line2y1, int line2x2, int line2y2){
    a1 = linef(line1x1, line1y1, line1x2, line1x2, line2x1, line2y1)
    a2 = linef(line1x1, line1y1, line1x2, line1x2, line2x2, line2y2)

    if((a1 > 0 and a2 > 0) or (a1 < 0 and a1 < 0)){
        return false
    }
    a3 = linef(line2x1, line2y1, line2x2, line2x2, line1x1, line1y1)
    a4 = linef(line2x1, line2y1, line2x2, line2x2, line1x2, line1y2)
    
    if((a3 > 0 and a4 > 0) or (a3 < 0 and a4 < 0)){
        return false
    }
}

void solve(){
    vector<pair<int, int>> circle(4);
    vector<pair<int, int>> triangle(4);

    FOR(i, 0, 4){
        int x, y;
        cin >> circle[i].F >> circle[i].S;
    }

    FOR(i, 0, 4){
        int x, y;
        cin >> triangle[i].F >> triangle[i].S;
    }

    



}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}