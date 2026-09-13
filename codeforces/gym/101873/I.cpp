/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        101873I — Uberwatch
 * Problem URL:    https://codeforces.com/gym/101873/problem/I
 *
 * Matched result: AC
 * Submission:     #332041141
 * Submission URL: https://codeforces.com/gym/101873/submission/332041141
 * Submitted:      2025-08-02 13:58:57 +0800
 * Language:       C++17 (GCC 7-32)
 * Runtime:        93 ms
 * Memory:         0 B
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-08-02 19:11:16 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T> >;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << " ";
    }
    cout << endl;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> dp(n, 0);
    FOR(i, 0, n){
        cin >> x[i];
    }

    FOR(i, m, n){
        dp[i] = max(dp[i-1], dp[i-m] + x[i]);
    }

    cout << dp[dp.size()-1];

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
