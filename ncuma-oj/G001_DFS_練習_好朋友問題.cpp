#include <iostream>
#include <vector>
#include <queue>

using namespace std;

signed main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector < vector < int > > arr(n);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int x;
    while(q--){
        cin >> x;

        vector < int > ans(n, 0);
        queue < int > visited;
        visited.push(x);
        while(!visited.empty()){
            int t = visited.front();
            visited.pop();

            for(int i=0; i<arr[t].size(); i++){
                if(ans[arr[t][i]]==0){
                    visited.push(arr[t][i]);
                    ans[arr[t][i]] = 1;
                }
            }
        }

        vector < int > friends;
        for(int i=0; i<n; i++){
            if(ans[i] and i!=x){
                friends.push_back(i);
            }
        }
        for(int i=0; i<friends.size(); i++){
            cout << friends[i];
            if(i<friends.size()-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
}