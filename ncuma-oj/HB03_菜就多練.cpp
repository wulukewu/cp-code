#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;

    vector < vector < int > > arr(n, vector < int > (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int a = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                a++;
            }
        }
    }

    int ans = 0;
    int y;
    while(a>0){
        ans++;
        y = 0;
        for(int i=0; i<n; i++){
            for(int j=y; j<m; j++){
                if(arr[i][j] == 1){
                    a--;
                    arr[i][j] = 0;
                    y = j;
                }
            }
        }
    }

    cout << ans;
}