#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(){
    int n;
    cin >> n;

    vector < int > arr;

    int a;
    while(n>0){
        a = n % 2;
        n /= 2;
        arr.push_back(a);
    }
    reverse(arr.begin(), arr.end());

    int m=arr.size();
    for(int i=0; i<m; i++){
        cout << arr[i];
    }
    cout << endl;

    return 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}