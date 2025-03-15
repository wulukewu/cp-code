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
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector <int> H(n);
    for(int i=0; i<n; i++){
        cin >> H[i];
    }

    int t=0;
    for(int i=0; i<n; i++){
        t += H[i] / 5 * 3;
        H[i] %= 5;

        while(H[i] > 0){
            t++;
            if(t%3==0){
                H[i] -= 3;
            }else{
                H[i]--;
            }
        }

    }
    cout << t;


}
