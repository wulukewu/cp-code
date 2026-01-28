// ==================================================
// Problem   : ABC380_D - Strange Mirroring
// URL       : https://atcoder.jp/contests/abc380/tasks/abc380_d
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
#include <math.h>
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector < int > K(q);
    for(int i=0; i<q; i++){
        cin >> K[i];
    }

    int n = s.size();
    int low2upp = 32;

    for(int i=0; i<q; i++){
        int t = (K[i]-1)%n;
        int k = K[i] - ((K[i]-1)%n+1);
        int rem = 0;
        char c;
        while(k>0){
            rem += k%n;
            k /= n;
        }
        if(rem%n==0){
            cout << s[t] << ' ';
        }else{
            if(s[t]>='a' && s[t]<='z'){
                c = s[t]-low2upp;
            }else{
                c = s[t]+low2upp;
            }
            cout << c << ' ';
        }
    }
}
