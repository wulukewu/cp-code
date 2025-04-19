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
    
    int n, m;
    cin >> n >> m;

    vector < int > arr(n, 0);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[(b+a)%n]++;
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    int ans = m*(m-1)/2;
    for(int i=0; i<n; i++){
        if(arr[i]>=2){
            ans -= arr[i]*(arr[i]-1)/2;
        }
    }

    cout << ans;
}
