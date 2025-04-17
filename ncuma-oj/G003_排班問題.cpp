#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < pair < int, int > > arr(n);
    int l, r;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        arr[i] = make_pair(r, l);
    }

    sort(arr.begin(), arr.end());
    // for(int i=0; i<n; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << endl;
    // }

    int a = 1;
    int b = arr[0].first;
    for(int i=1; i<n; i++){
        if(arr[i].second >= b){
            a++;
            b = arr[i].first;
        }
    }

    cout << a;
}