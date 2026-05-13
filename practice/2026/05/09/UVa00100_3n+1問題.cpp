#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, r;
    while(cin >> l >> r){
        int ans = 0;
        map<int, int>mp;
        for(int n=l; n<=r; n++){
            if(mp.find(n)!=mp.end()) continue;
            int m = n;
            int cnt = 0;
            vector<int>v(1, m);
            while(m>1){
                if(m%2==0){
                    m /= 2;
                }else{
                    m = 3*m+1;
                }
                cnt++;
                v.push_back(m);
            }
            for(int i=0; i<cnt; i++){
                mp[v[i]] = cnt-i+1;
            }
            ans = max(ans, mp[n]);
        }
        cout << l << ' ' << r << ' ' << ans << endl;
    }
}