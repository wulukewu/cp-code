// ==================================================
// Problem   : CPE 10273 - Eat or Not to Eat?
// URL       : https://onlinejudge.org/external/102/10273.pdf
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int t;
    cin >> t;

    int n, m;
    for(int tt=0; tt<t; tt++){
        cin >> n;

        vector < int > T(n);
        vector < vector < int > > arr(n);
        
        for(int i=0; i<n; i++){
            cin >> T[i];

            for(int j=0; j<T[i]; j++){
                cin >> m;
                arr[i].push_back(m);
            }
        }

        vector < int > alive(n, 1);

        int c = n;
        int d = 0;
        int ans_d = 0;
        int min;
        int min_idx;
        bool time_to_break;
        while(c>0){
            min = 251;
            min_idx = -1;
            time_to_break = true;
            for(int i=0; i<n; i++){
                if(alive[i]){
                    if(arr[i][d%T[i]] < min){
                        min = arr[i][d%T[i]];
                        min_idx = i;
                    }else if(arr[i][d%T[i]] == min){
                        min_idx = -1;
                    }

                    if((d-ans_d)%T[i]!=0){
                        time_to_break = false;
                    }

                    // cout << (d-ans_d) << ' ' << T[i] << endl;
                }
            }

            // cout << min_idx << ' ' << min << endl;

            if(min_idx != -1){
                alive[min_idx] = 0;
                c--;
                ans_d = d;
            }else if(time_to_break and d > 0){
                break;
            }
            d++;

            // for(int i=0; i<n; i++){
            //     cout << alive[i] << ' ';
            // }cout << endl;
            
            // c--;
            // if(d>50)break;
        }

        if(c==n){
            ans_d = 0;
        }else{
            ans_d++;
        }

        cout << c << ' ' << ans_d << endl;

    }
}