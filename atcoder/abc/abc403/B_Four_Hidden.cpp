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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string t, u;
    cin >> t >> u;

    int nt = t.size();
    int nu = u.size();

    for(int i=0; i<nt-nu+1; i++){
        bool det = false;
        for(int j=0; j<nu; j++){
            if(t[i+j]==u[j] or t[i+j]=='?'){
                continue;
            }else{
                det = true;
            }
        }
        if(!det){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
