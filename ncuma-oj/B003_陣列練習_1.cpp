#include <iostream>
#include <vector>

using namespace std;

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector < int > arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int t;
    cin >> t;

    int x, y, ans;
    for(int tt=0; tt<t; tt++){
        cin >> x;

        ans = 0;
        y = 1;
        for(int i=0; i<n; i++){
            ans += arr[i] * y;
            y *= x;
        }

        cout << ans << endl;
    }
}