#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define endl '\n'
//#define int long long
//#define float double
//#define float long double
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

void solve() {
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");
    int a,b;
    cin >> a >> b;
    bool check = true;
    if(b-a != 2) check = false;
    else if(a == 1) check = false;
    else{
        for(int i=2;i*i<=a;i++){
            if(a%i == 0){
                check = false;
                break;
            }
        }
        for(int i=2;i*i<=b;i++){
            if(b%i == 0){
                check = false;
                break;
            }
        }
    }
    if(check) cout << "Y" << endl;
    else cout << "N" << endl;
    
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
