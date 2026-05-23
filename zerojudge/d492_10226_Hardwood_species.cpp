#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t >> ws;
    while(t--){
        map<string, int>mp;
        string s;
        int n = 0;
        while(getline(cin, s)){
            if(s=="") break;
            mp[s]++;
            n++;
        }

        for(auto& i: mp){
            double num = (double) i.second * 100 / n;
            cout << i.first << ' ' << fixed << setprecision(4) << num << endl;
        }
        if(t>0) cout << endl;
    }

    // int t;
    // cin >> t;
    // string s;
    // for(int i=0; i<2; i++) getline(cin, s);
    // while(t--){
    //     map<string, int>mp;
    //     while(getline(cin, s)){
    //         if(s=="") break;
    //         // cout << s << endl;
    //         mp[s]++;
    //     }
    //     if(mp.empty()) continue;
    //     vector<pair<string, int>>v;
    //     int n = 0;
    //     for(auto& i: mp){
    //         v.push_back({i.first, i.second});
    //         n += i.second;
    //     }

    //     // auto cmp = [](pair<string, int>a, pair<string, int>b) -> bool {
    //     //     if(a.second!=b.second) return a.second>b.second;
    //     //     return a.first<b.first;
    //     // };
    //     sort(v.begin(), v.end());

    //     for(auto& i: v){
    //         double num = (double) i.second * 100 / n;
    //         // cout << i.first << ' ' << num << endl;
    //         // printf("%s %.4f\n", &i.first, num);
    //         // cout << i.first << ' ';
    //         // printf("%.4f\n", num);
    //         cout << i.first << ' ' << fixed << setprecision(4) << num << endl;
    //     }
    //     cout << endl;
    // }
}