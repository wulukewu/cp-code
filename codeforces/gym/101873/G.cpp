// ==================================================
// Problem   : 101873G - Unknown
// URL       : https://codeforces.com/contest/101873/problem/G
// ==================================================

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
    int n;
    cin >> n;
    
    int min_y = INT_MAX;
    int max_y = -INT_MAX;
    vector < pair < int, int > > arr(n);
    FOR(i, 0, n){
        cin >> arr[i].F >> arr[i].S;
        min_y = min(min_y, arr[i].S);
        max_y = max(max_y, arr[i].S);
    }
    cout << min_y << ' ' << max_y << endl;

    vector < pair < int, int > > v(max_y+5, make_pair(-INT_MAX, INT_MAX));
    FOR(i, 0, n){
        int x1 = arr[i].F;
        int y1 = arr[i].S;
        int x2 = arr[(i+1)%n].F;
        int y2 = arr[(i+1)%n].S;
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

        double m = (double)(y1-y2)/(x1-x2);
        double k = (double)((y2-y1) - m * (x2-x1));
        // cout << m << ' ' << k << endl;
        FOR(y, y1, y2+1){
            // int new_x;
            // if(x1==x2){
            //     new_x = x1;
            // }else{
            //     new_x = (int)((y-y1-k)/m)+x1;
            // }
            // cout << new_x << endl;
            auto func = [&](int intput_y) -> int {
                return ((intput_y-y1-k)/m)+x1;
            };
            cout << func(y) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

