#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int mod = 998244353;

    // string t;
    // int times;
    // for(int jj=0; jj<29; jj++){
    //     t = "";
    //     for(int i=1; i<n; i++){
    //         times = s[i] - '0';
    //         for(int j=0; j<times; j++){
    //             t += s[i-1];
    //         }
    //     }
    //     s = t;
    //     n = s.size();
    //     cout << s << ' ' << n << endl;
    // }

    int ans = 0;
    int j = 1;
    for(int i=1; i<n; i++){
        if(s[i-1]!='1' and s[i]!='1'){
            cout << -1;
            return 0;
        }

        j *= s[i] - '0';
        j %= mod;
        ans += j;
        ans %= mod;
    }

    cout << ans;

}

/*
5
31415

1
14
141
1415

1416
1*4(1*6+1)
1*(4(1*(5+1)+1)+1) mod

((((0+1)*5+1)*1+1)*4+1)*1+1=29
*/