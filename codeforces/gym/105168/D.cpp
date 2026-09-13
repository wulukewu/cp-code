/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105168D — XOR Pairing
 * Problem URL:    https://codeforces.com/gym/105168/problem/D
 *
 * Matched result: AC
 * Submission:     #333091513
 * Submission URL: https://codeforces.com/gym/105168/submission/333091513
 * Submitted:      2025-08-09 14:03:50 +0800
 * Language:       C++17 (GCC 7-32)
 * Runtime:        467 ms
 * Memory:         10.6 MiB
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-08-09 19:05:04 +0800
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
#define int long long
// #define float double
// #define float long double
#define FOR(i, a ,b) for(int i = a; i< b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve(){
    int n, k;
    cin >> n >> k;

    map < int, int > mp;
    int a;
    FOR(i, 0, n){
        cin >> a;
        if(mp.find(a)==mp.end()){
            mp[a] = 1;
        }else{
            mp[a]++;
        }
    }

    // for(auto i: mp){
    //     cout << i.F << ' ' << i.S << endl;
    // }

    int ans = 0;
    for(auto i: mp){
        int tar = k ^ i.F;
        // cout << tar << ' ';
        if(tar == i.F){
            ans += mp[tar]*(mp[tar]-1)/2;
        }else if(mp.find(tar)!=mp.end()){  
            ans += mp[tar]*i.S/2;
        }
    }
    // cout << endl;

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
