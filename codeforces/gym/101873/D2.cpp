// ==================================================
// Problem   : 101873D2.cpp - Unknown
// URL       : https://codeforces.com/contest/101873/problem/D2.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T> >;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << " ";
    }
    cout << endl;
}

void solve(){
    int n, m;
    cin >> n >> m;

    map < string, string > mp;
    string a, b, s;

    FOR(i, 0, n){
        cin >> a;
        FOR(j, 0, 3){
            cin >> s;
        }
        cin >> b;

        if(mp.find(b)==mp.end()){
            mp[b] = "top";
        }
        mp[a] = b;
    }

    for(auto i: mp){
        cout << i.F << ' ' << i.S << endl;
    }
    cout << endl;

    FOR(i, 0, m){
        cin >> a;
        FOR(j, 0, 3){
            cin >> s;
        }
        cin >> b;


        if(mp.find(a)==mp.end() or mp.find(b)==mp.end()){
            cout << "Pants on Fire" << endl;
        }else{
            string a_new = a, b_new = b;
            bool check = false;
            bool same = false;

            FOR(k,0,n){
                // cout << "a:" << a_new << " mp[a]:" << mp[a_new] << " b:" << b_new << " mp[b]:" << mp[b_new] << endl;
                // cout << endl;
                if(mp[a_new] == b){
                    check = true;
                    break;
                }else if(mp[b_new] == a){
                    check = false;
                    break;
                }else if(mp[a_new] == "top" and mp[b_new] == "top"){
                    same = true;
                    break;
                }
                if(mp[a_new] != "top"){
                    a_new = mp[a_new];
                }if(mp[b_new] != "top"){
                    b_new = mp[b_new];
                }
            }
            // while(mp[a] != "top"){
            //     cout << a << " " << mp[a] << endl;
            //     if(mp[a] == b){
            //         check = true;
            //         break;
            //     }else{
            //         mp[a] = a;
            //     }
            // }
            // while(mp[b] != "top" and not check){
            //     if(mp[b] == a){
            //         same = false;
            //         break;
            //     }else{
            //         mp[b] = b;
            //     }
            // }
            if(same){
                cout << "Pants on Fire" << endl;
            }else if(check){
                cout << "Fact" << endl;
            }else{
                cout << "Alternative Fact" << endl;
            }
            // cout << endl;
        }
        
        
        // else if(mp[a]<mp[b]){
        //     cout << "Fact" << endl;
        // }else if(mp[a]>mp[b]){
        //     cout << "Alternative Fact" << endl;
        // }else{
        //     cout << "Pants on Fire" << endl;
        // }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

