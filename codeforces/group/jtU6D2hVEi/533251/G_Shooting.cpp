// ==================================================
// Problem   : jtU6D2hVEiG - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/G
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
    int n;
    cin >> n;

    map < string, int > mp;
    set < string > name_set;
    vector < string > name_vector;

    string name;
    int score;
    FOR(i, 0, n){
        cin >> name >> score;
        if(mp.find(name)==mp.end()){
            mp.insert(make_pair(name, score));
        }else{
            mp[name] += score;
        }

        if(name_set.find(name)==name_set.end()){
            name_set.insert(name);
            name_vector.PB(name);
        }
    }

    // for(auto i: mp){
    //     cout << i.F << ' ' << i.S << endl;
    // }

    int max_score = 0;
    for(auto i: mp){
        max_score = max(max_score, i.S);
    }
    cout << max_score << endl;

    int cnt = 0;
    for(string i: name_vector){
        if(mp[i]==max_score){
            if(cnt>0) cout << ',';
            cout << i;
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
