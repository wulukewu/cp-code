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

ll MOD = 1e9+7;
const double EPS = 1e-9;
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a,ll b) {ll res=1; do{if(b%2)timesmod(res,a); timesmod(a,a);}while(b>>=1); return res;}
void solve(){

    int p;
    while(cin >> p){
        MOD = p;
        // cout << p << endl;
        if(p == 0){
            break;
        }
        vector<int>v;
        int xx = -1;
        while(xx != 0){
            cin >> xx;
            if(xx == 0) break;
            v.PB(xx);
        }

        bool pisprime = true;
        for(int i = 2; i*i <= p; i++){
            if(p%i == 0){
                cout << p << " is not a prime.\n";
                pisprime = false;
                break;
            }
        }
        if(not pisprime) continue;
        if((p+1)%4 != 0){
            cout << p << "+1 is not divisible by 4.\n";
            continue;
        }
        int a = (p-1)/2 , b = (p+1)/4;
        for(int c : v){
            if(POW(c,a) != 1){
                cout << "0 ";
                continue;
            }
            int ans = POW(c,b);
            if(ans > p/2) ans = p - ans;
            cout << ans << " ";
        }
        cout << endl;
    };
    
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}