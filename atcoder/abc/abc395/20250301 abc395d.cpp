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
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector < set < int > > arr(n);
    vector <int> brr(n);
    for(int i=0; i<n; i++){
        arr[i].insert(i+1);
        brr[i] = i+1;
    }

    int c, a, b;
    set < int > tmp;
    for(int i=0; i<q; i++){
        cin >> c;
        if(c==1){
            cin >> a >> b;
            arr[brr[a-1]-1].erase(a);
            arr[b-1].insert(a);
            brr[a-1] = b;
        }else if(c==2){
            cin >> a >> b;
            if(arr[a-1].size()>0){
                for(int x: arr[a-1]){
                    brr[x-1] = b;
                }
            }
            if(arr[b-1].size()>0){
                for(int x: arr[b-1]){
                    brr[x-1] = a;
                }
            }
            tmp = arr[a-1];
            arr[a-1] = arr[b-1];
            arr[b-1] = tmp;
        }else{
            cin >> a;
            cout << brr[a-1] << endl;
        }
    }
}
