// ==================================================
// Problem   : ABC430_C - Truck Driver
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc430/tasks/abc430_c
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

void solve() {
    // int n, a, b;
    // cin >> n >> a >> b;
    int n, A, B;
    cin >> n >> A >> B;

    string s;
    cin >> s;

    vector < int > v(n+1, 0);
    int a = 0, b = 0;
    int j = 0;
    int ans = 0;
    FOR(i, 0, n){
        while(j<n and b<B){
            if(s[j]=='a') a++;
            else b++;
            // if(s[j]=='a') v[j+1] = v[j]+1;
            // else v[j+1] = v[j];
            v[j+1] = v[j] + (s[j]=='a');
            j++;
        }
        int x = lower_bound(v.begin()+i+1, v.begin()+j+1, A+v[i])-v.begin();
        if(a>=A){
            // if(b<B) ans += j-x+1;
            // else ans += j-x;
            ans += j-x+(b<B);
        }
        if(s[i]=='a') a--;
        else b--;
    }
    cout << ans << endl;

    // int l = 0, r = 0;
    // int cnt_a = 0, cnt_b = 0;
    // int ans = 0;

    // if(s[0]=='a') cnt_a++;
    // else cnt_b++;

    // while(l<n and r<n){
    //     // cout << l << ' ' << r << ' ' << cnt_a << ' ' << cnt_b << endl;
    //     if(cnt_a<a){
    //         r++;
    //         if(s[r]=='a') cnt_a++;
    //         else cnt_b++;
    //     }
    //     if(cnt_b>=b){
    //         if(s[l]=='a') cnt_a--;
    //         else cnt_b--;
    //         l++;
    //     }
    //     if(cnt_a>=a and cnt_b<b){
    //         // cout << l << ' ' << r << endl;
    //         ans++;

    //         int aa, bb;
    //         int ll = l;
    //         aa = cnt_a, bb = cnt_b;
    //         while(ll<r){
    //             if(s[ll]=='a') aa--;
    //             else bb--;
    //             ll++;

    //             if(aa>=a and bb<b){
    //                 // cout << ll << ' ' << r << endl;
    //                 ans++;
    //             }else{
    //                 break;
    //             }
    //         }
    //         int rr = r;
    //         aa = cnt_a, bb = cnt_b;
    //         while(rr<n){
    //             rr++;
    //             if(s[rr]=='a') aa++;
    //             else bb++;

    //             if(aa>=a and bb<b){
    //                 // cout << l << ' ' << rr << endl;
    //                 ans++;
    //             }else{
    //                 break;
    //             }
    //         }

    //         if(s[l]=='a') cnt_a--;
    //         else cnt_b--;
    //         l++;
    //         r++;
    //         if(s[r]=='a') cnt_a++;
    //         else cnt_b++;    
    //     }
    // }
    // cout << ans << endl;

    // set < pair < int, int > > st;
    // queue < pair < pair < int, int >, pair < int, int > > > q;
    // q.push({{0, 0}, {cnt_a, cnt_b}});
    // while(!q.empty()){
    //     auto t = q.front();
    //     q.pop();
    //     int l = t.F.F;
    //     int r = t.F.S;
    //     int x = t.S.F;
    //     int y = t.S.S;
    //     if(!(l<n and r<n)) continue;
    //     // cout << l << ' ' << r << ' ' << x << ' ' << y << endl;

    //     if(x<a){
    //         if(s[r+1]=='a') q.push({{l, r+1}, {x+1, y}});
    //         else q.push({{l, r+1}, {x, y+1}});
    //     }else if(y>=b){
    //         if(s[l]=='a') q.push({{l+1, r}, {x-1, y}});
    //         else q.push({{l+1, r}, {x, y-1}});
    //     }else if(x>=a and y<b){
    //         // cout << l << ' ' <<  r << endl;
    //         st.insert({l, r});

    //         if(s[l]=='a') q.push({{l+1, r}, {x-1, y}});
    //         else q.push({{l+1, r}, {x, y-1}});
    //         if(s[r+1]=='a') q.push({{l, r+1}, {x+1, y}});
    //         else q.push({{l, r+1}, {x, y+1}});
    //     }
    // }

    // cout << st.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
