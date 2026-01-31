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
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
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
template<typename T>
class fenwick{
public:
    vector<T>bit;
    int size;
    fenwick(int s){size=s;bit=vector<T>(size,0);}
    int lb(int x){return x&(-x);}
    void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
    T sum(int x){T res=0;for(int i=x;i>0;i-=lb(i))res+=bit[i];return res;}
};

void solve(){
    int n;
    cin >> n;
    // int minh = n;
    vector<int>arr(n);
    FOR(i, 0, n){
        cin >> arr[i];
        // minh = min(minh, arr[i]);
    }

    vector<int>brr = arr;
    FOR(i, 1, n){
        brr[i] = min(brr[i], brr[i-1]+1);
    }
    for(int i=n-2; i>=0; i--){
        brr[i] = min(brr[i], brr[i+1]+1);
    }

    // queue<pair<int, pair<int, int>>>q;
    // FOR(i, 0, n){
    //     if(arr[i]==minh){
    //         q.push({i, {minh, 1}});
    //         q.push({i, {minh, -1}});
    //     }
    // }

    // // int offs[2] = {1, -1};
    // int offsh[3] = {1, 0, -1};
    // // vector<int>brr = arr;
    // vector<int>brr(n, minh);
    // while(!q.empty()){
    //     auto t = q.front();
    //     q.pop();

    //     int x = t.F;
    //     int h = t.S.F;
    //     int a = t.S.S;
    //     // for(int a: offs){
    //     int y = x + a;
    //     if(!(y>=0 and y<n)) continue;
    //     for(int b: offsh){
    //         int k = h + b;
    //         if(k<minh) continue;
    //         if(k>arr[y]) continue;
    //         if(arr[y]-k<arr[y]-brr[y]){
    //             brr[y] = k;
    //             // cout << y << ' ' << k << endl;
    //             q.push({y, {k, a}});
    //         }
    //     }
    //     // }
    // }
    // print(brr);
    
    int ans = 0;
    FOR(i, 0, n){
        ans += arr[i] - brr[i];
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
