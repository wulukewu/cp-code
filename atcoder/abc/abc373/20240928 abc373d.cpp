// ==================================================
// Problem   : ABC373_D - Hidden Weights
// URL       : https://atcoder.jp/contests/abc373/tasks/abc373_d
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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector <int> u(m);
    vector <int> v(m);
    vector <int> w(m);

    for(int i=0; i<m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }

    vector < vector <int> > uv(n);
    vector < vector <int> > vu(n);
    vector < vector <int> > uw(n);
    vector < vector <int> > vw(n);

    for(int i=0; i<m; i++){
        uv[u[i]-1].push_back(v[i]-1);
        vu[v[i]-1].push_back(u[i]-1);
        uw[u[i]-1].push_back(w[i]);
        vw[v[i]-1].push_back(w[i]);
    }

    for(int i=0; i<n; i++){
        int s = uv[i].size();
        cout << i << ": ";
        for(int j=0; j<s; j++){
            cout << uv[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        int s = vu[i].size();
        cout << i << ": ";
        for(int j=0; j<s; j++){
            cout << vu[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        int s = uw[i].size();
        cout << i << ": ";
        for(int j=0; j<s; j++){
            cout << uw[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        int s = vw[i].size();
        cout << i << ": ";
        for(int j=0; j<s; j++){
            cout << vw[i][j] << ' ';
        }
        cout << endl;
    }

    vector < int > x(n);
    int i = 0;
    x[i] = 0;

}
