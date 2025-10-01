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

void solve() {
    int n;
    cin >> n;

    vector < vector < int > > v(n+1);
    int a;
    FOR(i, 0, n){
        cin >> a;
        v[a].PB(i);
    }
    // FOR(i, 0, n+1){
    //     cout << i << ": ";
    //     print(v[i]);
    // }

    bool ans = true;
    vector < int > arr;
    FOR(i, 0, n+1){
        int m = v[i].size();
        if(m<=1) continue;
        // print(v[i]);
        bool sc = v[i][0]==0;

        // sort(ALL(v[i]));
        if(v[i][m-1]-v[i][0]!=m-1){
            if(sc){
                if(v[i][m-1]!=n-1){
                    ans = false;
                    arr.PB(i);
                    continue;
                }
                int c = 0;
                FOR(j, 0, m-1){
                    if(v[i][j+1]-v[i][j]!=1){
                        c++;
                    }
                }
                if(c>1){
                    ans = false;
                    arr.PB(i);
                }
            }else{
                ans = false;
                arr.PB(i);
            }
        }
        


    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
        print(arr);
    }

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
