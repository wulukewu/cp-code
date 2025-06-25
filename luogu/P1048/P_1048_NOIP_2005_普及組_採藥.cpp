#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, m;
    cin >> t >> m;

    vector < int > w(m);
    vector < int > v(m);
    for(int i=0; i<m; i++){
        cin >> w[i] >> v[i];
    }

    vector < vector < int > > dp(m, vector < int > (t+1, -1));
    for(int i=0; i<m; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=t; j++){
        if(j>=w[0]) dp[0][j] = v[0];
        else dp[0][j] = 0;
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<=t; j++){
            if(j>=w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<=t; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[m-1][t];
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int t, m;
// vector < pair < int, int > > arr;
// vector < vector < int > > brr;

// int dfs(int a, int tr, int ans){
//     // cout << a << ' ' << tr << ' ' << ans << endl;
//     if(a==m){
//         return ans;
//     }

//     if(brr[tr][ans]>-1){
//         return brr[tr][ans];
//     }

//     int d1, d2;
//     if(tr>=arr[a].first){
//         d1 = dfs(a+1, tr-arr[a].first, ans+arr[a].second);
//     }else{
//         d1 = 0;
//     }
//     d2 = dfs(a+1, tr, ans);

//     brr[tr][ans] = max(d1, d2);
//     return brr[tr][ans];
// }

// int main(){
//     cin >> t >> m;

//     arr = vector < pair < int, int > >(m);
//     int tt, mm;
//     for(int i=0; i<m; i++){
//         cin >> tt >> mm;
//         arr[i] = make_pair(tt, mm);
//     }

//     brr = vector < vector < int > > (t+5, vector < int > (m+5, -1));

//     cout << dfs(0, t, 0);
// }