// ==================================================
// Problem   : 101667I - Unknown
// URL       : https://codeforces.com/contest/101667/problem/I
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin() v.end()
#define PB .push_back
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
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b + MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    FOR(i,0,n) cin >> nums[i];
    // print(nums);
    // cout << 9/2;
    int k=n,p=n;
    FOR(i,1,n/2+1){
        int test = n-1,k_new = test;
        bool check = true;
        FOR(j,0,i){
            // if(test-j < 0) break;
            // cout << test-j << " " << test-j-i << endl;
            if(nums[test-j] == nums[test-j-i]) check = true;
            else{
                // cout << "NO" << endl;
                check = false;
                break;
            }
        }
        if(check){
            test = n-i;
            k_new = test - i;
        }
        else continue;
        while(nums[test] == nums[test-i]){
            // cout << test << "    " << k_new << endl;
            test -= 1;
            if(test-i < 0) break;
            if(nums[test] == nums[test-i]) k_new = test-i;
        }
        // cout << k << " " << p << " " << k_new << " " << i << endl;
        if((k_new+i) < (k+p)){
            k = k_new;
            p = i;
        }
        else if((k_new+i) == (k+p) and i < p){
            k = k_new;
            p = i;
        }
    }
    // cout << endl;
    if(p==n){
        k = n-1;
        p = 1;
    }
    cout << k << " " << p << endl;
}


int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}