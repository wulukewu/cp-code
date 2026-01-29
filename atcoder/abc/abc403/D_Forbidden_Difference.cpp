// ==================================================
// Problem   : ABC403_D - Forbidden Difference
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc403/tasks/abc403_d
// ==================================================

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
// #define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, d;
    cin >> n >> d;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(d==0){
        map < int, int > mp;
        for(int i=0; i<n; i++){
            if(mp.find(arr[i]) == mp.end()){
                mp.insert(make_pair(arr[i], 1));
            }else{
                mp[arr[i]]++;
            }
        }

        int s = 0;
        for(auto i: mp){
            s += i.second-1;
        }

        cout << s;
    }else{
        vector < map < int, int > > brr(d);
        int a, b;
        for(int i=0; i<n; i++){
            a = arr[i]%d;
            b = arr[i]/d;
            if(brr[a].find(b) != brr[a].end()){
                brr[a][b]++;
            }else{
                brr[a].insert(make_pair(b, 1));
            }
        }
    
        int s = 0;
        a = 0;
        b = 0;
        int c;
        for(int i=0; i<d; i++){
            c=-1;
            for(auto j: brr[i]){
                // cout << j.first << ' ' << j.second << endl;
                if(c==-1 or j.first-c==1){
                    if(j.first%2){
                        a += j.second;
                    }else{
                        b += j.second;
                    }
                }else{
                    s += min(a, b);
                    a = 0;
                    b = 0;
                }
                c = j.first;
            }
            s += min(a, b);
            a = 0;
            b = 0;
            // cout << s << endl;
        }

        cout << s;

        // vector < int > dp(n, 1);

        // for(int i=1; i<n; ++i){
        //     for(int j=0; j<i; ++j){
        //         if(abs(arr[i]-arr[j]) != d){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;

        // int ml = 0;
        // for(int i=0; i<n; ++i){
        //     ml = max(ml, dp[i]);
        // }

        // cout << n-ml;
    }

}
