#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

signed main(){
    int a, b;
    string s;
    int x, ans;
    int n;
    while(cin >> a){
        cin.ignore();
        getline(cin, s);

        // cout << a << ' ' << s << endl;

        stringstream ss(s);
        vector < int > arr;

        while(ss >> b){
            arr.push_back(b);
        }

        x = 1;
        ans = 0;
        n = arr.size();
        for(int i=n-2; i>=0; i--){
            // cout << arr[i] * x << ' ';
            // cout << n-1-i << ' ';
            ans += arr[i] * x * (n-1-i);
            x *= a;
        }

        cout << ans << endl;

        
    }
}