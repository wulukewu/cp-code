// ==================================================
// Problem   : ABC413_B - cat 2
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc413/tasks/abc413_b
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

    vector < string > s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    set < string > st;
    string t;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            t = s[i] + s[j];
            if(st.find(t) == st.end()){
                st.insert(t);
            }
            
            t = s[j] + s[i];
            if(st.find(t) == st.end()){
                st.insert(t);
            }
        }
    }

    cout << st.size();
}
