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
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
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
template<typename T>
class fenwick{
public:
    vector<T>bit;
    int size;
    fenwick(int s){size=s;bit=vector<T>(size,0);}
    int lb(int x){return x&(-x);}
    void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
    T sum(int x){T res=0;for(int i=x;i>0;i-=lb(i))res+=bit[i];return res;}
};

void solve(){
    int n, c;
    cin >> n >> c;
    c--;
    vector<vector<bool>>arr(n, vector<bool>(n, false));
    FOR(i, 0, n){
        string s;
        cin >> s;
        FOR(j, 0, n){
            if(s[j]=='#') arr[i][j] = true;
        }
    }

    vector<int>wall(n, -1);
    FOR(j, 0, n){
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]){
                wall[j] = i;
                break;
            }
        }
    }
    // print(wall);

    vector<bool>dp(n, false);
    vector<bool>dp2(n, false);
    dp[c] = true;
    dp2[c] = true;

    int offs[3] = {-1, 0, 1};
    for(int i=n-1; i>0; i--){
        vector<bool>dp_next(n, false);
        vector<bool>dp2_next(n, false);
        int row = i-1;
        FOR(j, 0, n){
            if(!dp[j]) continue;
            for(int d: offs){
                int col = j + d;
                if(!(col>=0 and col<n)) continue;

                bool det = false;
                bool det2 = false;
                if(arr[row][col]){
                    if(d==0){
                        if(dp2[j]){
                            det = true;
                            det2 = true;
                        }
                    }else{
                        if(wall[col]<i){
                            det = true;
                            det2 = true;
                        }
                    }
                }else{
                    det = true;
                    if(d==0){
                        if(dp2[j]) det2 = true;
                    }else{
                        if(wall[col]<i) det2 = true;
                    }
                }

                if(det){
                    dp_next[col] = true;
                    if(det2) dp2_next[col] = true;
                }
            }
        }

        dp = dp_next;
        dp2 = dp2_next;
    }
    // print(dp);
    // print(dp2);

    FOR(j, 0, n){
        if(dp[j]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
