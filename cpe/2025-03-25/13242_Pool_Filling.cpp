// ==================================================
// Problem   : CPE 13242 - Pool Filling
// URL       : https://onlinejudge.org/external/132/13242.pdf
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int C, T;
        cin >> C >> T;

        int n;
        cin >> n;

        vector < int > v(n+2, 0);
        vector < int > t(n+2, 0);
        vector < int > w(n+2, 0);
        for(int i=0; i<n; i++){
            cin >> v[i+1] >> t[i+1];
            w[i+1] = v[i+1] * t[i+1];
        }

        for(int i=1; i<=n; i++){
            v[i] += v[i-1];
            t[i] += t[i-1];
            w[i] += w[i-1];
        }

        // for(int i=0; i<=n; i++){
        //     cout << v[i] << ' ';
        // }
        // cout << endl;
        // for(int i=0; i<=n; i++){
        //     cout << t[i] << ' ';
        // }
        // cout << endl;
        // for(int i=0; i<=n; i++){
        //     cout << w[i] << ' ';
        // }
        // cout << endl;

        long double w_temp, v_temp;
        long double temp;
        int L = -1;
        int R = -1;
        long double temp_ans = -1;
        for(int l=1; l<=n; l++){
            for(int r=l; r<=n; r++){
                w_temp = w[r]-w[l-1];
                v_temp = v[r]-v[l-1];
                temp = w_temp / v_temp;
                // cout << temp << endl;
                if(abs(temp-T)<=5 and (abs(temp-T)<abs(temp_ans-T) or temp_ans==-1) and v_temp*2>=C and v_temp<=C){
                    temp_ans = temp;
                    L = l-1;
                    R = r-1;
                }
            }
        }

        // cout << L << ' ' << R << ' ' << temp << endl;
        if(temp_ans==-1){
            cout << "Not possible" << endl;
        }else{
            cout << L << ' ' << R << endl;
        }
    }
}