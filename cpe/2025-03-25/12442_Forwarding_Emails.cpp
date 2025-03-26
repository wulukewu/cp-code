#include <iostream>
#include <vector>

using namespace std;

// vector < int > brr;

int dfs(vector < vector < int > > arr, vector < int > went, int k){
    // cout << "call dfs" << endl;
    int y = 0;
    int yy;

    for(auto i: arr[k]){
        if(went[i]){
            continue;
        // }else if(brr[i] != -1){
        //     yy = brr[i];
        }else{
            went[i] = 1;
            yy = dfs(arr, went, i);
            went[i] = 0;
            // brr[i] = yy;
        }

        if(yy>y){
            y = yy;
        }
    }

    // brr[k] = y+1;
    return y+1;
}

int main(){
    int t;
    cin >> t;

    for(int case_t=0; case_t<t; case_t++){
        int n;
        cin >> n;

        vector < vector < int > > arr(n);
        int u, v;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            arr[u-1].push_back(v-1);
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<arr[i].size(); j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        // vector < int > brr(n, -1);
        // brr = vector < int > (n, 1);

        vector < int > went(n, 0);
        int ans = 0;
        int max_y = 0;
        int y_tmp;
        for(int i=0; i<n; i++){
            went[i] = 1;
            y_tmp = dfs(arr, went, i);
            went[i] = 0;
            if(y_tmp > max_y){
                max_y = y_tmp;
                ans = i + 1;
            }
        }

        cout << "Case " << case_t+1 << ": " << ans << endl;
    }
}