#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector < string > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    queue < pair < int, int > > q;
    for(int i=0; i<n; i++){
        q.push({i, 0});
        q.push({i, m-1});
    }
    for(int j=0; j<m; j++){
        q.push({0, j});
        q.push({n-1, j});
    }

    int offs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int cnt = 0;
    vector < vector < bool > > v(n, vector < bool > (m, false));
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(v[r][c]) continue;
        else if(arr[r][c]=='.'){
            v[r][c] = true;
            cnt++;
        }else{
            continue;
        }

        for(int k=0; k<4; k++){
            int x = r + offs[k][0];
            int y = c + offs[k][1];
            if(!(x>=0 and x<n and y>=0 and y<m)) continue;
            if(!v[x][y] and arr[x][y]=='.'){
                q.push({x, y});
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}