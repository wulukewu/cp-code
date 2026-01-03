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

void solve(){
    int n;
    cin >> n;

    vector<map<int, vector<int>>>arr(3);
    int a;
    FOR(i, 0, n){
        cin >> a;
        if(a%7==0) arr[0][a/7].PB(i+1);
        if(a%5==0) arr[1][a/5].PB(i+1);
        if(a%3==0) arr[2][a/3].PB(i+1);
    }

    int ans = 0;
    for(auto i: arr[1]){
        int m = i.F;
        for(int j: i.S){
            int x = lower_bound(ALL(arr[0][m]), j) - arr[0][m].begin();
            int cntx = arr[0][m].size();
            int y = lower_bound(ALL(arr[2][m]), j) - arr[2][m].begin();
            int cnty = arr[2][m].size();

            // cout << x << ' ' << y << ' ' << cntx << ' ' << cnty << endl;
            ans += x * y;
            ans += (cntx-x)*(cnty-y);
        }
    }
    cout << ans << endl;


    // vector<int>arr(n);
    // FOR(i, 0, n) cin>>arr[i];

    // vector<pair<int, int>>vi;
    // vector<pair<int, int>>vj;
    // vector<pair<int, int>>vk;

    // // map<int,int>mpi;
    // // map<int,int>mpk;

    // FOR(i, 0, n){
    //     if(arr[i]%7==0){
    //         vi.PB({arr[i], i});
    //         // mpi[arr[i]]++;
    //     }
    //     if(arr[i]%5==0){
    //         vj.PB({arr[i], i});
    //     }
    //     if(arr[i]%3==0){
    //         vk.PB({arr[i], i});
    //         // mpk[arr[i]]++;
    //     }
    // }

    // // sort(ALL(vi));
    // // sort(ALL(vj));
    // // sort(ALL(vk));

    // // print(vi);
    // // print(vj);
    // // print(vk);
    // for(auto i: vi) cout << i.F << ' ';
    // cout << endl;
    // for(auto j: vj) cout << j.F << ' ';
    // cout << endl;
    // for(auto k: vk) cout << k.F << ' ';
    // cout << endl;
    // // for(auto i: mpi){
    // //     cout << i.F << ":" << i.S << ' ';
    // // }
    // // cout << endl;
    // // for(auto i: mpk){
    // //     cout << i.F << ":" << i.S << ' ';
    // // }
    // // cout << endl;

    // int ans = 0;
    // for(auto j: vj){
        
    // }

    // // int ans = 0;
    // // for(int j: vj){
    // //     for(auto i: mpi){
    // //         if(i.F*5==j*7){
    // //             int a = j/5*3;
    // //             if(mpk.find(a)!=mpk.end()){
    // //                 // if((j>i.F and j>a) or (j<i.F and j<a))
    // //                 cout << i.S << '*' << mpk[a] << '=' << i.S*mpk[a] << endl;
    // //                 ans += i.S * mpk[a];
    // //             }
    // //         }
    // //     }
    // // }
    // // cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
