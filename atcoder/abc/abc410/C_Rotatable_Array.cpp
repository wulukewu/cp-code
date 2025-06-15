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
    int n, q;
    cin >> n >> q;

    vector < int > a(n);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }

    int m = 0;
    int t;
    while(cin >> t){
        if(t==1){
            int p, x;
            cin >> p >> x;

            a[(p-1+m)%n] = x;
        }else if(t==2){
            int p;
            cin >> p;

            cout << a[(p-1+m)%n] << endl;
        }else{
            int k;
            cin >> k;

            m += k;
        }
    }
}
