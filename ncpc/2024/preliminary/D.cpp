#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'


void solve(){
    int m = 10003;
    int n, a, d;

    while(true){
        vector < int > dp(m, 0);
        bool end = true;
        while(true){
            cin >> n;
            if(n==0) break;
            cin >> a >> d;
            dp[a] += n;
            dp[d] -= n;
            end = false;
        }
        if(end) break;
        for(int i=1; i<m; i++){
            dp[i] += dp[i-1];
        }
    
        // for(int i=0; i<10; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;
    
        int larg = -1;
        for(int i=0; i<m; i++){
            larg = max(larg, dp[i]);
        }
        cout << larg << ": ";
    
        int l = -1, r = -1;
        for(int i=0; i<m; i++){
            if(dp[i]==larg){
                if(l==-1){
                    l = i;
                    r = i;
                }
            }else{
                if(r!=-1){
                    r = i;
                    cout << "[" << l << "," << r << ") ";
                    l = -1;
                    r = -1;
                }
            }
        }
        cout << endl;
    }
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}
