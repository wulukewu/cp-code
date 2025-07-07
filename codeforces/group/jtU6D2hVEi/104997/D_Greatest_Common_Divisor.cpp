#include <iostream>
#include <vector>
#define int long long

using namespace std;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

signed main(){
    int n;
    cin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector < int > brr(n);
    vector < int > crr(n);

    brr[0] = arr[0];
    for(int i=1; i<n; i++){
        brr[i] = gcd(brr[i-1], arr[i]);
    }

    crr[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        crr[i] = gcd(crr[i+1], arr[i]);
    }

    // for(int i=0; i<n; i++){
    //     cout << brr[i] << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     cout << crr[i] << ' ';
    // }
    // cout << endl;

    int ans = 0;
    ans = max(ans, crr[1]); // first idx=0
    ans = max(ans, brr[n-2]); // last idx=n-2

    for(int i=1; i<n-1; i++){
        ans = max(ans, gcd(brr[i-1], crr[i+1]));
    }

    cout << ans;
}