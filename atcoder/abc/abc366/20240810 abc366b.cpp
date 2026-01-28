// ==================================================
// Problem   : ABC366_B - Vertical Writing
// URL       : https://atcoder.jp/contests/abc366/tasks/abc366_b
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n;
    m = 0;

    vector <string> S(n);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        S[i] = s;
        if(m<s.size()){m=s.size();}
    }

    vector < vector <char> > T(m, vector <char> (n, '*'));
    for(int i=0; i<n; i++){
        for(int j=0; j<S[i].size(); j++){
            // cout << S[i][j] << endl;
            T[j][n-i-1] = S[i][j];
        }
    }

    vector <int> t(m);
    for(int i=0; i<m; i++){
        int jj=0;
        for(int j=0; j<n; j++){
            if(T[i][j]!='*'){
                jj = j;
            }
        }
        // cout << jj << ' ';
        t[i] = jj;
    }
    // cout << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(j>t[i]){break;}
            cout << T[i][j];
        }
        cout << endl;
    }


}
