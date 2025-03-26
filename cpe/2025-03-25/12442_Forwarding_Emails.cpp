#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector < int > brr;

int dfs(vector < vector < int > > arr, vector < int > went, int k){
    // cout << "call dfs" << endl;
    int y = 0;
    int yy;

    for(auto i: arr[k]){
        if(went[i]){
            continue;
        }else if(brr[i] != -1){
            yy = brr[i];
        }else{
            went[i] = 1;
            yy = dfs(arr, went, i);
            went[i] = 0;
        }

        if(yy>y){
            y = yy;
        }
    }

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

        vector < int > l;
        int last, l_size;
        brr = vector < int > (n, -1);
        for(int i=0; i<n; i++){
            stack < vector < int > > togo;
            togo.push(vector < int > (1, i));
            while(!togo.empty()){
                l = togo.top();
                togo.pop();

                last = l[l.size()-1];
                l_size = l.size();
                if(brr[last] != -1){
                    for(int j=l_size-2; j>=0; j--){
                        brr[l[j]] = max(brr[l[j]], brr[l[j-1]]+1);
                    }
                    continue;
                }

                bool det = false;
                for(int j=0; j<l_size-1; j++){
                    if(last == l[j]){
                        det = true;
                        break;
                    }
                }

                if(det){
                    for(int j=1; j<l_size; j++){
                        brr[l[l_size-1-j]] = j;
                    }
                }
                // if(last == i and l_size > 1){
                //     for(int j=0; j<l_size; j++){
                //         brr[l[j]] = l_size-1;
                //     }
                // }

                for(int j=0; j<arr[last].size(); j++){
                    l.push_back(arr[last][j]);
                    togo.push(l);
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     cout << brr[i] << ' ';
        // }
        // cout << endl;

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