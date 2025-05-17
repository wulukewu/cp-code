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
    int n, k;
    cin >> n >> k;

    int a;
    int m = 1;
    string mm;
    for(int i=0; i<n; i++){
        cin >> a;
        if(1e18/a < m){
            m = 1;
            continue;
        }
        m *= a;
        mm = to_string(m);
        // cout << mm << endl;
        if(mm.length() > k){
            m = 1;
        }
    }

    cout << m;
}
