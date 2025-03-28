#include <iostream>
#include <vector>
// #include <map>

using namespace std;

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector < int > dp(n, 0);
        dp[1] = 1;
        dp[2] = 1;

        for(int i=2; i<n; i++){
            if(s[i] == s[i-2]){
                dp[i+1] = dp[i+1-2] + 1;
            }else{
                dp[i+1] = 1;
            }
        }

        // for(int i=0; i<=n; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;

        int l, r, l1, r1, l2, r2;
        while(q--){
            cin >> l >> r;

            l1 = l;
            if(l%2==0)l1++;
            l2 = l;
            if(l%2==1)l2++;
            r1 = r;
            if(r%2==0)r1--;
            r2 = r;
            if(r%2==1)r2--;

            if(dp[r1]-dp[l1]+1 == (r1-l1)/2+1 and dp[r2]-dp[l2]+1 == (r2-l2)/2+1){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }

        /* 2nd try
        vector < vector < pair < int, int > > > arr(n+1, vector < pair < int, int > > (52, make_pair(0, 0)));

        int asc;
        for(int i=1; i<=n; i++){
            for(int j=0; j<52; j++){
                arr[i][j] = arr[i-1][j];
            }
            
            if('a'<=s[i-1] and s[i-1]<='z'){
                asc = s[i-1]-'a';
            }else if('A'<=s[i-1] and s[i-1]<='Z'){
                asc = s[i-1]-'A'+26;
            }else{
                asc = 0;
            }

            if(i%2){
                arr[i][asc].first++;
            }else{
                arr[i][asc].second++;
            }
        }

        int l, r;
        int a, b;
        bool ans;
        vector < pair < int, int > > brr;
        while(q--){
            cin >> l >> r;

            brr.clear();
            ans = true;
            for(int i=0; i<52; i++){
                a = arr[r][i].first - arr[l-1][i].first;
                b = arr[r][i].second - arr[l-1][i].second;

                if(a or b){
                    brr.push_back(make_pair(a, b));
                    if(brr.size() > 2){
                        ans = false;
                        break;
                    }
                }
            }

            // for(auto i: brr){
            //     cout << i.first << ' ' << i.second << endl;
            // }

            if(brr.size() == 1){
                ans = true;
            }else if(brr.size() == 2){
                if(abs(brr[0].first-brr[1].second)<=1 or abs(brr[0].second-brr[1].first)<=1){
                    if((s[l-1]==s[r-1] and (r-l+1)%2==1) or (s[l-1]!=s[r-1] and (r-l+1)%2==0)){
                        ans = true;
                    }else{
                        ans = false;
                    }
                }else{
                    ans = false;
                }
            }else{
                ans = false;
            }

            if(ans){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }
        */

        /* 1st try
        map < char, pair < int, int > > mp;
        vector < map < char, pair < int, int > > > arr(n+1);
        
        arr[0] = mp;
        for(int i=1; i<n+1; i++){
            if(mp.find(s[i-1]) == mp.end()){
                if(i%2){
                    mp.insert(make_pair(s[i-1], make_pair(1, 0)));
                }else{
                    mp.insert(make_pair(s[i-1], make_pair(0, 1)));
                }
            }else{
                if(i%2){
                    mp[s[i-1]].first++;
                }else{
                    mp[s[i-1]].second++;
                }
            }

            arr[i] = mp;
        }

        // for(auto i: mp){
        //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
        // }
        
        int l, r;
        bool ans;
        map < char, pair < int, int > > mpa;
        map < char, pair < int, int > > mpl;
        map < char, pair < int, int > > mpr;
        while(q--){
            cin >> l >> r;
            
            mpl = arr[l-1];
            mpr = arr[r];

            // for(auto i: mpl){
            //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
            // }
            // for(auto i: mpr){
            //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
            // }

            ans = true;
            mpa.clear();
            for(auto i: mpr){
                if(mpl.find(i.first) == mpl.end()){
                    mpa.insert(i);
                }else{
                    i.second.first -= mpl[i.first].first;
                    i.second.second -= mpl[i.first].second;
                    if(i.second.first or i.second.second){
                        mpa.insert(i);
                    }
                }
            }

            // for(auto i: mpa){
            //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
            // }
            // cout << "---" << endl;

            if(mpa.size() == 1){
                ans = true;
            }else if(mpa.size() == 2){
                auto it = mpa.begin();
                pair < char, pair < int, int > > i1 = *it;
                it++;
                pair < char, pair < int, int > > i2 = *it;

                if(abs(i1.second.first-i2.second.second)<=1 or abs(i1.second.second-i2.second.first)<=1){
                    ans = true;
                }else{
                    ans = false;
                }
            }else{
                ans = false;
            }

            if(ans){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }
        */
    }
}