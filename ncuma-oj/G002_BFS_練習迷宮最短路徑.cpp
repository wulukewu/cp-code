#include <iostream>
#include <vector>
#include <queue>

using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;

    vector < string > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = -1;
    int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int x, y, z;
    vector < vector < int > > visited(n, vector < int > (m, 0));
    queue < pair < int, pair < int, int > > > q;
    q.push(make_pair(0, make_pair(0, 0)));
    visited[0][0] = 1;
    while(!q.empty()){
        z = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();

        // cout << z << ' ' << x << ' ' << y << endl;

        if(x==n-1 and y==m-1){
            ans = z;
            break;
        }

        for(int i=0; i<4; i++){
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            
            if(0<=xx and xx<n and 0<=yy and yy<m){
                if(arr[xx][yy]=='0' and visited[xx][yy]==0){
                    visited[xx][yy] = 1;
                    q.push(make_pair(z+1, make_pair(xx, yy)));
                }
            }
        }
    }

    cout << ans;
}