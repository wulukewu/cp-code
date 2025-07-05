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
    int q;
    cin >> q;

    queue < pair < int, int > > qu;
    
    int type, c, x, k, ans;
    while(q--){
        cin >> type;
        if(type==1){
            cin >> c >> x;
            qu.push(make_pair(c, x));
        }else{
            cin >> k;
            ans = 0;
            while(k>0){
                if(k>=qu.front().first){
                    k -= qu.front().first;
                    ans += qu.front().first * qu.front().second;
                    // cout << qu.front().first << ' ' << qu.front().second << endl;
                    qu.pop();
                }else{
                    qu.front().first -= k;
                    ans += k * qu.front().second;
                    // cout << k << ' ' << qu.front().second << endl;
                    k = 0;
                }
            }
            cout << ans << endl;
        }
    }
}
