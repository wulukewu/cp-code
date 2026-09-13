/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc414_c — Palindromic in Both Bases
 * Problem URL:    https://atcoder.jp/contests/abc414/tasks/abc414_c
 *
 * Matched result: AC
 * Submission:     #67554462
 * Submission URL: https://atcoder.jp/contests/abc414/submissions/67554462
 * Submitted:      2025-07-12 21:27:22 +0800
 * Language:       C++ 20 (gcc 12.2)
 * Runtime:        991 ms
 * Points:         350.0
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-07-12 21:29:57 +0800
 * Match policy:   matched by contest path and filename/title; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

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

int a;

bool check(string s){
    // cout << s << endl;
    int num = stoll(s);
    string t = "";
    while(num>0){
        t += to_string(num%a);
        num /= a;
    }
    // cout << t << endl;

    string ss = s;
    reverse(ALL(ss));
    string tt = t;
    reverse(ALL(tt));
    if(t==tt and s==ss){
        return true;
    }else{
        return false;
    }
}

void solve() {
    int n;
    cin >> a >> n;

    int n_size = 0;
    int nn = n;
    while(nn>0){
        nn /= 10;
        n_size++;
    }

    // cout << n_size << endl;

    int ans = 0;

    auto dfs = [&](string s, auto&& self) -> void {
        // if((s.size()+1)*2>n_size) return;
        if(s.size()>(n_size+1)/2) return;

        if(s.size()==0){
            FOR(i, 1, 10){
                if(check(to_string(i)) and i<=n){
                    // cout << i << endl;
                    ans += i;
                }
            }
        }

        if(s.size()*2<=n_size and s.size()>0){
            string ss = s;
            reverse(ALL(ss));
            if(check(s+ss) and stoll(s+ss)<=n){
                // cout << s+ss << endl;
                ans += stoll(s+ss);
            }
        }
        if(s.size()*2+1<=n_size and s.size()>0){
            string ss = s;
            reverse(ALL(ss));
            FOR(i, 0, 10){
                if(check(s+to_string(i)+ss) and stoll(s+to_string(i)+ss)<=n){
                    // cout << s+to_string(i)+ss << endl;
                    ans += stoll(s+to_string(i)+ss);
                }
            }
        }

        FOR(i, 0, 10){
            if(s.size()==0 and i==0) continue;
            self(s+to_string(i), self);
        }
    };

    dfs("", dfs);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
