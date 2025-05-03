#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector < vector < char > > s(n, vector < char > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    vector < vector < char > > t(n, vector < char > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> t[i][j];
        }
    }

    int ans = 1e9;
    for(int rot=0; rot<4; rot++){
        int diff = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i][j] != t[i][j]){
                    diff++;
                }
            }
        }

        ans = min(ans, diff + rot);
        vector < vector < char > > next_s(n, vector < char > (n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                next_s[j][n-1-i] = s[i][j];
            }
        }
        s = next_s;
    }
    cout << ans << endl;
}