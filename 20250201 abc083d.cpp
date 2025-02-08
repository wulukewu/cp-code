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
    
    string s;
    cin >> s;

    int n = s.size();

    // int count_0 = 0;
    // int count_1 = 0;
    // for(int i=0; i<n; i++){
    //     if(s[i]=='0'){
    //         count_0++;
    //     }else{
    //         count_1++;
    //     }
    // }

    // cout << max(count_0, count_1);

    // int sum = 0;
    // for(int i=0; i<n; i++){
    //     sum += s[i] - '0';
    //     s[i] = sum % 2 + '0';
    // }
    // cout << s;

    vector < int > arr;
    char current = s[0];
    int count = 1;
    for(int i=1; i<n; i++){
        if(s[i]!=current){
            arr.push_back(count);
            count = 1;
            current = s[i];
        }else{
            count ++;
        }
    }
    arr.push_back(count);

    int m = arr.size();
    // for(int i=0; i<m; i++){
    //     cout << arr[i] << ' ';
    // }

    int ans = n;
    if(m==1){
        ans = n;
    }else{
        ans = 0;
        vector < int > arrb(m);
        arrb[0] = arr[0];
        for(int i=1; i<m; i++){
            arrb[i] = arrb[i-1] + arr[i];
        }
        for(int i=0; i<m; i++){
            ans = max(min(arrb[i], n-arrb[i]+arr[i]), ans);
            // cout << arrb[i] << n-arrb[i]+arr[i] << endl;
        }
    }

    cout << ans;

}

/*
01011111010
n=11
1115111

---
1011111010
n=10
115111

k=7
1011111010 115111
1000000101 16111 k<=8
1111111010 7111 k<=9
---
101111101
n=9
11511

101111101 11511
100000010 1611 k<=7
011111110 171 k<=7
100000000 18 k<=8
111111111 9 k<=9
---
011111010101

n=12
15111111

k=6
011111010101
000000110101
000000001010

k=7
011111010101
000000100101
---
010
n=3

k=2
010
100
111
000
---
01111101

n=8
1511

k=5
8%5!=1
00000000
11111000
10000100
10111010
10100101

01111101
00000001
01111111
00000000

01111101
11111111
*/