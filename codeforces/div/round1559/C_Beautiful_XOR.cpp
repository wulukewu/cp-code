// ==================================================
// Problem   : round1559C - Unknown
// URL       : https://codeforces.com/contest/round1559/problem/C
// ==================================================

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
#define int long long
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
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
template <typename T>
void printQ(queue < T > q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
template <typename T>
void printPQ(priority_queue < T > pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

string bit(int x){
    string s = "";
    while(x>0){
        if(x%2==0){
            s  = '0' + s;
        }else{
            s = '1' + s;
        }
        x /= 2;
    }
    return s;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int a2 = a;
    string ba = bit(a), bb = bit(b);
    int sa = ba.size(), sb = bb.size();
    // cout << ba << ' ' << bb << endl;
    if(a==b){
        cout << 0 << endl;
    }else if(sa<sb){
        cout << -1 << endl;
    }else{
        FOR(i, 0, sa-sb){
            bb = '0' + bb;
        }
        // cout << ba << ' ' << bb << endl;
        
        vector < int > ans;
        int p = 1;
        for(int i=sa-1; i>=0; i--){
            if(ba[i]!=bb[i]){
                ans.PB(p);
            }
            p *= 2;
        }
        reverse(ALL(ans));
        // print(ans);

        vector < int > ans2;
        int c = 0;
        for(int i: ans){
            if(c^i>a){
                ans2.PB(c);
                a ^= c;
                c = i;
            }else{
                c ^= i;
            }
        }
        ans2.PB(c);
        print(ans2);

        // if(ans.size()<=100){
        //     cout << ans.size() << endl;
        //     print(ans);
        // }else{
        //     int i = 0, c = 0;
        //     while(i < ans.size()){
        //         if(c^ans[i]>a){
        //             break;
        //         }
        //         c ^= ans[i];
        //         i++;
        //     }
        //     if(ans.size()-c<=100){
        //         cout << ans.size()-c << endl;
        //         cout << c << ' ';
        //         print(ans);
        //     }else{
        //         cout << -1 << endl;
        //     }
        // }
    }
    // cout << '-' << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
