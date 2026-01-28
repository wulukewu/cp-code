// ==================================================
// Problem   : jtU6D2hVEiC - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/C
// ==================================================

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
    int n1, n2, n3, n4;

    cin >> n1;
    vector < int > a1(n1);
    FOR(i, 0, n1) cin >> a1[i];
    cin >> n2;
    vector < int > a2(n2);
    FOR(i, 0, n2) cin >> a2[i];
    cin >> n3;
    vector < int > a3(n3);
    FOR(i, 0, n3) cin >> a3[i];
    cin >> n4;
    vector < int > a4(n4);
    FOR(i, 0, n4) cin >> a4[i];

    sort(ALL(a1));
    sort(ALL(a2));
    sort(ALL(a3));
    sort(ALL(a4));

    set < int > s;
    FOR(i, 0, n1) s.insert(a1[i]);
    FOR(i, 0, n2) s.insert(a2[i]);
    FOR(i, 0, n3) s.insert(a3[i]);
    FOR(i, 0, n4) s.insert(a4[i]);

    // for(int i: s){
    //     cout << i << ' ';
    // }
    // cout << endl;

    int colors_cnt = s.size();
    vector < int > brr;
    for(int i: s) brr.PB(i);

    int ans_diff = MOD;
    vector < int > ans(4, -1);
    for(int i: brr){
        auto it1 = lower_bound(ALL(a1), i);
        auto it2 = lower_bound(ALL(a2), i);
        auto it3 = lower_bound(ALL(a3), i);
        auto it4 = lower_bound(ALL(a4), i);
        if(it1==a1.end() or it2==a2.end() or it3==a3.end() or it4==a4.end()) break;

        int c1 = *it1;
        int c2 = *it2;
        int c3 = *it3;
        int c4 = *it4;
        // cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << endl;

        vector < int > crr(4);
        crr[0] = c1;
        crr[1] = c2;
        crr[2] = c3;
        crr[3] = c4;

        int diff = 0;
        FOR(i, 0, 4){
            FOR(j, i+1, 4){
                diff = max(diff, abs(crr[i]-crr[j]));
            }
        }
        // cout << diff << endl;

        if(diff<ans_diff){
            ans = crr;
            ans_diff = diff;
        }
        if(ans_diff==0) break;
    }

    FOR(i, 0, 4){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
