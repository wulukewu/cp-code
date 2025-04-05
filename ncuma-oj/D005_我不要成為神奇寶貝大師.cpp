#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < pair < int, string > > arr;

    string s;
    int a, b, c;
    int iv;
    for(int i=0; i<n; i++){
        cin >> s >> a >> b >> c;

        iv = (a + b + c) * 100 / 45;
        arr.push_back(make_pair(iv, s));
    }

    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        cout << arr[i].second << ' ' << arr[i].first << endl;
    }

    cout << "The weaknest pokemon is: " << arr[0].second;
}