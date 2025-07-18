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
    int a, b;
    cin >> a >> b;

    queue < int > q;
    map < int, int > prev;
    map < int, char > op;

    q.push(b);
    prev[b] = 0;
    op[b] = ' ';

    while(!q.empty()){
        int c = q.front();
        q.pop();

        if(c==a) break;

        int next = c - 1;
        if(next>=a and prev.find(next)==prev.end()){
            q.push(next);
            prev[next] = c;
            op[next] = '+';
        }

        if(c%2==0){
            next = c / 2;
            if(next>=a and prev.find(next)==prev.end()){
                q.push(next);
                prev[next] = c;
                op[next] = '*';
            }
        }
    }

    // for(auto i: prev){
    //     cout << i.first << ' ' << i.second << endl;
    // }
    // for(auto i: op){
    //     cout << i.first << ' ' << i.second << endl;
    // }

    string ans = to_string(a);
    int now = a;
    while(now!=b){
        if(op[now]=='+'){
            ans = "(" + ans + " + 1)";
        }else{
            ans = ans + " * 2";
        }
        now = prev[now];
    }

    cout << b << " = " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
