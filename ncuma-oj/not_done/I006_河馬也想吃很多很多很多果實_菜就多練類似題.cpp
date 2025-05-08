#include <iostream>
#include <vector>
#include <set>

using namespace std;

signed main(){
    int n;
    cin >> n;

    int m = 1;

    int x, y;
    set < pair < int, int > > s;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        s.insert(make_pair(x, y));
        m = max(m, x);
        m = max(m, y);
    }

    // cout << m << endl;

    vector < vector < int > > dp(m+1, vector < int > (m+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            if(s.find(make_pair(i-1, j-1)) != s.end()){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[m][m];

}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> fruits(n);
    for (int i = 0; i < n; ++i) {
        cin >> fruits[i].first >> fruits[i].second;
    }

    // Sort fruits by x-coordinate, then by y-coordinate.
    sort(fruits.begin(), fruits.end());

    vector<int> dp(n, 1); // Initialize each fruit to be reachable by itself.

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // If fruit j is reachable and fruit i can be reached from fruit j.
            if (fruits[i].first >= fruits[j].first && fruits[i].second >= fruits[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_fruits = 0;
    for (int i = 0; i < n; ++i) {
        max_fruits = max(max_fruits, dp[i]);
    }

    cout << max_fruits << endl;

    return 0;
}
*/