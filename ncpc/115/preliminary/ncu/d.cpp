#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    int m = 2*n;
    int sz = 0;
    vector<string>inp(m);
    FOR(i, 0, m){
        cin >> inp[i];
        sz += inp[i].length();
    }
    sz /= n;

    map<int, set<string>>mp;
    FOR(i, 0, m){
        mp[inp[i].size()].insert(inp[i]);
    }
    // for(auto p: mp){
    //     cout << p.F << ' ';
    //     for(string s: p.S){
    //         cout << s << ' ';
    //     }
    //     cout << endl;
    // }

    string ans;
    for(auto p: mp){
        for(string s1: p.S){
            for(string s2: mp[sz-p.F]){
                // cout << s1 << ' ' << s2 << endl;
                for(auto p2: mp){
                    // if(p2.F==p.F or p2.F==sz-p.F) continue;
                    for(string s3: p2.S){
                        for(string s4: mp[sz-p2.F]){
                            // if(s1==s3 or s1==s4) continue;
                            if((s1==s3 or s1==s4) and (s2==s3 or s2==s4)) continue;
                            // cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << endl;
                            if(s1+s2==s3+s4 or s1+s2==s4+s3){
                                cout << s1+s2 << endl;
                            }else if(s2+s1==s3+s4 or s2+s1==s4+s3){
                                cout << s2+s1 << endl;
                            }else{
                                continue;
                            }
                            return;
                        }
                    }
                }
                ans = s1+s2;
            }
        }
        break;
    }
    cout << ans << endl;

    
    // vector<set<string>>v(sz+1);
    // FOR(i, 0, m){
    //     v[inp[i].size()].insert(inp[i]);
    // }
    // FOR(i, 1, sz+1){
    //     for(string s: v[i]){
    //         cout << s << ' ';
    //     }
    //     cout << endl;
    // }

}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}