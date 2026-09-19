#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector< vector<int> > mp(n,vector<int>(n+1,0));
    vector<bool> red(n*n+1,true);
    vector<bool> blue(n*n+1,true);
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // bool ok = true;
    for(int i=0;i<n;i++){
        // if(!ok) break;
        int l = n*i+1 , r = n*(i+1);

        for(int j=1;j<=n;j++){
            if(mp[i][j] < l && mp[i][j] > r) red[mp[i][j]] = false;
            else if(mp[i][j] != n*i+j) blue[mp[i][j]] = false;
        }

        int check = -1;
        for(int j=1;j<=n;j++){
            if(mp[i][j] >= l && mp[i][j] <= r){
                if(mp[i][j] > check) check = mp[i][j];
                else{
                    if(mp[i][j] == n*i+j) blue[n*i+j] = true;
                    else ok = false;
                }
            }
        }
    }
    for(int j=1;j<=n;j++){
        // if(!ok) break;
        int check = -1;
        for(int i=0;i<n;i++){
            if(mp[i][j]%n == i){
                if(mp[i][j] > check) check = mp[i][j];
                else{
                    if(mp[i][j] != n*i+j) ok = false;
                    else if()
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}