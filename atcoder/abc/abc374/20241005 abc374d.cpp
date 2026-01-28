// ==================================================
// Problem   : ABC374_D - Laser Marking
// URL       : https://atcoder.jp/contests/abc374/tasks/abc374_d
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

int n, s, t;
vector <int> A;
vector <int> B;
vector <int> C;
vector <int> D;
int went_count;
vector <int> went;

long double dfs(int x, int y){
    float a, b, c, d;
    if(went_count == n){
        return 0;
    }else{
        for(int i=0; i<n; i++){
            if(went[i]==0){
                went[i] = 1;
                went_count += 1;
                b = sqrt(pow(A[i]-C[i], 2) + pow(B[i]-D[i], 2));
                c = sqrt(pow(x-C[i], 2) + pow(y-D[i], 2));
                d = sqrt(pow(x-A[i], 2) + pow(y-B[i], 2));
                
                a += min(dfs(A[i], B[i]) + c/t, dfs(C[i], D[i]) + d/t) + d/s;
            }
        }
    }
    return a;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> s >> t;

    A.resize(n);
    B.resize(n);
    C.resize(n);
    D.resize(n);

    for(int i=0; i<n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    went_count = 0;
    went.resize(n, 0);
    cout << dfs(0,0);
}
