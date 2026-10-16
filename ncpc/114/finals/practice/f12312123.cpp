#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define ing long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

using uint = unsigned;
using ull = unsigned int long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;
const double EPS = 1e-9;

void solve(){
    int n;
    cin >> n;
    vector<int> alls(n+1,0);
    vector<string> ses(n+1);
    vector<int> nums(n+1,0);
    bool check = false;
    for(int i=1;i<=n;i++){
        cin >> ses[i];
        int cnt = count(ALL(ses[i]),'1');
        alls[i] = cnt;
        nums[cnt]++;
        if(nums[cnt] != 1) check = true;
    }
    if(!check){
        cout << n << " 1\n"; 
        return;
    }

    int ans_small = n+1 , ans_cnt = 0;
    for(int i=1;i<=n;i++){
        bool ok = true;
        vector<int> nums(n+1,0);
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            int cnt = alls[j] - (ses[j][i-1] == '1');
            nums[cnt]++;
            if(nums[cnt] != 1){
                ok = false;
                break;
            }
        }
        if(ok){
            ans_small = min(ans_small,i);
            ans_cnt++;
        }
    }
    if(ans_cnt == 0) cout << 0 << endl;
    else cout << ans_cnt << " " << ans_small << endl;
    
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}