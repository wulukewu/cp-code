#include <iostream>
#include <vector>

using namespace std;

vector < vector < int > > arr;
vector < int > c;

signed dfs(int x, int ori, vector < int >& visited){
    int y = 0;

    if(c[x]==c[ori] and x!=ori){
        return 1;
    }

    for(int i=0; i<arr[x].size(); i++){
        if(visited[arr[x][i]]==0){
            visited[arr[x][i]] = 1;
            y += dfs(arr[x][i], ori, visited);
            visited[arr[x][i]] = 0;
        }
    }

    return y;
}

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        c = vector < int > (n);
        for(int i=0; i<n; i++){
            cin >> c[i];
        }

        int v, u;
        arr = vector < vector < int > > (n);
        for(int i=0; i<n-1; i++){
            cin >> v >> u;
            arr[v-1].push_back(u-1);
            arr[u-1].push_back(v-1);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            vector < int > visited(n, 0);
            visited[i] = 1;
            ans += dfs(i, i, visited);
        }

        ans /= 2;

        cout << ans << endl;
    }
}