#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    // cout << n << ' ' << m << endl;

    vector < pair < string, int > > arr(n);
    string s;
    int a;
    for(int i=0; i<n; i++){
        cin >> s >> a;
        // cout << s << ' ' << a << endl;
        arr[i] = make_pair(s, a);
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << endl;
    // }

    vector < string > ans;
    bool det = false;
    for(int i=n-1; i>=0; i--){
        // cout << arr[i].first << ' ' << arr[i].second << endl;
        if(det){
            ans.push_back(arr[i].first);
        }else if(arr[i].second > m){
            det = true;
            ans.push_back("菜就多練");
            ans.push_back(arr[i].first);
        }
    }

    if(ans.size() == 0){
        cout << "恭喜打完所有屁屁" << endl;
    }else{
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << endl;
        }
    }
}