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
    string r;
    cin >> r;

    int n = r.size();
    int ans = 0;

    if(r[0]=='u'){
        r[0] = 's';
        ans++;
    }
    if(r[n-1]=='u'){
        r[n-1] = 's';
        ans++;
    }

    stack<pair<char,int>>st;
    FOR(i, 0, n){
        if(st.empty() or st.top().F!=r[i]){
            st.push({r[i], 1});
        }else{
            st.top().S++;
        }
    }

    while(!st.empty()){
        auto t = st.top();
        st.pop();
        // cout << t.F << ' ' << t.S << endl;
        if(t.F=='u'){
            ans += t.S/2;
        }
    }
    cout << ans << endl;

    // int ans = 0;
    // FOR(i, 0, n){
    //     int idx;
    //     if(i%2==0){
    //         idx = i/2;
    //     }else{
    //         idx = n-1-i/2;
    //     }
    //     // cout << "idx: " << idx << endl;
    //     if(r[idx]=='u'){
    //         bool det = false;
    //         FOR(j, 1, idx+1){
    //             if(r[idx-j]=='s' and r[idx+j]=='s'){
    //                 det = true;
    //                 break;
    //             }
    //         }
    //         if(!det){
    //             ans++;
    //             r[idx] = 's';
    //         }
    //     }
    //     // cout << "r: " << r << endl;
    // }
    // cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
