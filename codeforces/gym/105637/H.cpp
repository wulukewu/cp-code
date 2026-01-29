// ==================================================
// Problem   : 105637H - Unknown
// URL       : https://codeforces.com/contest/105637/problem/H
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
// #define long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b) % MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD) % MOD;}
void timesmod(ll &a, ll b) {a = (a*b) % MOD;}
ll POW(ll a, ll b){ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1);return res;}
template<typename T> void print(T a){for(auto u:a){cout<<u<<' ';}cout<<endl;}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<bool> v(n+1, false);
    vector<int> v1;
    vector<int> v2;
    bool is = true;
    bool is2 = true;
    FOR(i, 0, m){
        v1.clear();
        int idx = 0;

        FOR(j, 1, n+1){
            int s;
            cin >> s;
            if(s == 0){
                v1.PB(j);
                idx += 1;
            }else if(s == 1){
                v[i] = true;
            }
            if(idx >= m){
                is = false;
                break;
            }
        }

        if(is == false){
            break;
        }
    }
    

    // FOR(i, 1, n+1){
    //     if(v[i] == false){
    //         is2 = false;
    //         v2.PB(i);
    //         break;
    //     }
    // }

    // int wrongidx = v2[0];

    // if(v2.size() == 1){
    //     FOR(i, 1, m){
    //         if(i == wrongidx){
    //             v2.PB(m);
    //         }else{
    //             v2.PB(i);
    //         }
    //     }
    // }

    if(is){
        if(is2){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
            print(v2);
        }
    }else{
        cout << 0 << endl;
        print(v1);
    }





}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}