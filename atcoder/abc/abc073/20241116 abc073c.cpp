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
    
    int n;
    cin >> n;

    vector <int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    map < int, int > arr;
    map < int, int > :: iterator it;
    for(int i=0; i<n; i++){
        if(arr.find(A[i])!=arr.end()){
            arr.find(A[i])->second++;
        }else{
            arr.insert(make_pair(A[i], 1));
        }
    }

    int ans = 0;
    for(it=arr.begin(); it!=arr.end(); it++){
        if(it->second%2==1){
            ans++;
        }
    }

    cout << ans << endl;


}
