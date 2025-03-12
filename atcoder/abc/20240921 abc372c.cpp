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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector < int > X(q);
    vector < char > C(q);
    for(int i=0; i<q; i++){
        int x;
        char c;
        cin >> x >> c;
        X[i] = x;
        C[i] = c;
    }

    int m=0;
    for(int i=0; i<n-2; i++){
        if(s[i]=='A' and s[i+1]=='B' and s[i+2]=='C'){
            m += 1;
        }
    }
    // cout << m << endl;

    for(int j=0; j<q; j++){
        string s2 = s;
        int i = X[j]-1;
        s2[X[j]-1] = C[j];
        // cout << s << ' ' << s2 << endl;

        if(i+2<n){
            if((s[i]=='A' and s[i+1]=='B' and s[i+2]=='C') and (s2[i]!='A' or s2[i+1]!='B' or s2[i+2]!='C')){
                m -= 1;
            }
            if((s[i]!='A' or s[i+1]!='B' or s[i+2]!='C') and (s2[i]=='A' and s2[i+1]=='B' and s2[i+2]=='C')){
                m += 1;
            }
        }
        if(i>=1 and i+1<n){
            if((s[i-1]=='A' and s[i]=='B' and s[i+1]=='C') and (s2[i-1]!='A' or s2[i]!='B' or s2[i+1]!='C')){
                m -= 1;
            }
            if((s[i-1]!='A' or s[i]!='B' or s[i+1]!='C') and (s2[i-1]=='A' and s2[i]=='B' and s2[i+1]=='C')){
                m += 1;
            }
        }
        if(i>=2 and i<n){
            if((s[i-2]=='A' and s[i-1]=='B' and s[i]=='C') and (s2[i-2]!='A' or s2[i-1]!='B' or s2[i]!='C')){
                m -= 1;
            }
            if((s[i-2]!='A' or s[i-1]!='B' or s[i]!='C') and (s2[i-2]=='A' and s2[i-1]=='B' and s2[i]=='C')){
                m += 1;
            }
        }
        cout << m << endl;
        s = s2;

    }

}
