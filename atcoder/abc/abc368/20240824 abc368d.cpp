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

int n, k;
vector < vector <int> > arr;
vector <int> V;
vector <int> VV;
vector <int> went;
vector <int> togo;
vector <int> ANS;

int dfs(int x){
    cout << x << endl;
    int ans = 0;

    
    for(int i=0; i<k; i++){
        if(V[i] == x){
            VV[i] = 1;
            break;
        }
    }

    bool det = true;
    for(int i=0; i<k; i++){
        if(VV[i]==0){
            det = false;
            break;
        }
    }
    if(det){
        return 1;
    }

    int ii = arr[x-1].size();
    for(int i=0; i<ii; i++){
        int y = arr[x-1][i];
        if(went[y-1]==0){
            togo.push_back(y);
        }
    }

    int ij = togo.size();
    for(int i=0; i<ij; i++){
        int y = togo[i];
        togo.erase(togo.begin(), togo.begin()+1);
        went[y-1] = 1;
        ans += dfs(y);
        went[y-1] = 0;
        togo.push_back(y);
    }
    cout << "ans: " << ans << endl;
    ANS.push_back(ans);
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> k;

    vector <int> A(n-1);
    vector <int> B(n-1);
    for(int i=0; i<n-1; i++){
        cin >> A[i] >> B[i];
    }

    // vector < vector <int> > arr(n);
    arr = vector < vector <int> > (n);
    for(int i=0; i<n-1; i++){
        arr[A[i]-1].push_back(B[i]);
        arr[B[i]-1].push_back(A[i]);
    }

    // for(int i=0; i<n; i++){
    //     int ss = arr[i].size();
    //     for(int j=0; j<ss; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    V = vector <int> (k);
    for(int i=0; i<k; i++){
        cin >> V[i];
    }

    VV = vector <int> (k,0);
    went = vector <int> (n,0);
    went[V[0]-1] = 1;
    int p = dfs(V[0]);
    // cout << p;

    int mn = n;
    int ans_size = ANS.size();
    for(int i=0; i<ans_size; i++){
        mn = min(mn, ANS[i]);
    }
    cout << mn+1;
}
