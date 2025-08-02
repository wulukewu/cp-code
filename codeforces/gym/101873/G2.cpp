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
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    FOR(i, 0, n){
        cin >> x[i] >> y[i];
    }

    int area2 = 0;
    int B = 0;

    FOR(i, 0, n){
        int j = (i+1) % n;
        area2 += x[i]*y[j] - x[j]*y[i];
        B += std::gcd(abs(x[j]- x[i]), abs(y[j]-y[i]));
    }

    area2 = abs(area2);

    int ans = (area2 - B + 2) / 2;

    cout << ans << endl;

    
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

