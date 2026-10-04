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
    int size = 0;
    vector<string>words(m);
    FOR(i, 0, m){
        cin >> words[i];
        size += words[i].length();
    }
    size /= n;

    

    vector<string> v1;
    vector<string> vsizemione;

    vector<string> v2;
    vector<string> vsizemitwo;

    for(int i = 0; i < words.size(); i++){
        if(words[i].size() == 1){
            v1.push_back(words[i]);
        }

        if(words[i].size() == 2){
            v2.push_back(words[i]);
        }

        if(words[i].size() == (size-1)){
            vsizemione.push_back(words[i]);
        }

        if(words[i].size() == (size-2)){
            vsizemitwo.push_back(words[i]);
        }
    }

    if(v1.size() == 1){
        v1.push_back(v1[0]);
    }

    if(v2.size() == 1){
        v2.push_back(v2[0]);
    }

    if(vsizemione.size() == 1){
        vsizemione.push_back(vsizemione[0]);
    }

    if(vsizemitwo.size() == 1){
        vsizemitwo.push_back(vsizemitwo[0]);
    }

    vector<string>group1 = {
        v1[0]+vsizemione[0], vsizemione[0]+v1[0],
        v1[1]+vsizemione[0], vsizemione[1]+v1[0],
        v1[0]+vsizemione[1], vsizemione[0]+v1[1],
        v1[1]+vsizemione[1], vsizemione[1]+v1[1]
    };

    vector<string>group2 = {
        v2[0]+vsizemitwo[0], vsizemitwo[0]+v2[0],
        v2[1]+vsizemitwo[0], vsizemitwo[1]+v2[0],
        v2[0]+vsizemitwo[1], vsizemitwo[0]+v2[1],
        v2[1]+vsizemitwo[1], vsizemitwo[1]+v2[1]
    };

    string ans = "";

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(group1[i] == group2[j]){
                ans = group1[i];
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}