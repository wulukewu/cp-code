#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < pair < int, pair < int, string > > > arr(n);
    string a;
    int b, c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        arr[i] = make_pair(-b, make_pair(c, a));
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        b = -arr[i].first;
        c = arr[i].second.first;
        a = arr[i].second.second;
        cout << a << ' ' << b << ' ' << c << endl;
    }
}