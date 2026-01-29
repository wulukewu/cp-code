// ==================================================
// Problem   : 101873D3 - Unknown
// URL       : https://codeforces.com/contest/101873/problem/D3
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

    int siz = 0;
    map < string, int > mp;
    vector < vector < string > > v;
    string a, b, s;

    FOR(i, 0, n){
        cin >> a;
        FOR(j, 0, 3) cin >> s;
        cin >> b;

        if(mp.find(a)==mp.end()){
            mp[a] = siz;
            v.PB(vector < string >());
            siz++;
        }
        if(mp.find(b)==mp.end()){
            mp[b] = siz;
            v.PB(vector < string >());
            siz++;
        }

        v[mp[a]].PB(b);
    }

    // for(auto i: mp){
    //     cout << i.F << ' ' << i.S << endl;
    // }
    // FOR(i, 0, siz){
    //     print(v[i]);
    // }
    // cout << "---" << endl;

    FOR(i, 0, m){
        cin >> a;
        FOR(j, 0, 3) cin >> s;
        cin >> b;

        if(mp.find(a)==mp.end() or mp.find(b)==mp.end()){
            cout << "Pants on Fire" << endl;
            continue;
        }

        bool is_fact = false;
        queue < string > q;
        q.push(a);
        while(!q.empty()){
            string t = q.front();
            q.pop();

            if(t == b){
                is_fact = true;
                break;
            }
            
            // cout << "v[mp[t]]: ";
            // print(v[mp[t]]);
            for(string t2: v[mp[t]]){
                q.push(t2);
            }
        }

        if(is_fact){
            cout << "Fact" << endl;
        }else{
            bool alt_fact = false;
            queue < string > q2;
            q2.push(b);
            while(!q2.empty()){
                string t = q2.front();
                q2.pop();

                if(t == a){
                    alt_fact = true;
                    break;
                }
                
                // cout << "v[mp[t]]: ";
                // print(v[mp[t]]);
                for(string t2: v[mp[t]]){
                    q2.push(t2);
                }
            }
            if(alt_fact){
                cout << "Alternative Fact" << endl;
            }else{
                cout << "Pants on Fire" << endl;
            }
        }
    }

    // for(auto i: mp){
    //     cout << i.F << ' ' << i.S << endl;
    // }

    // FOR(i, 0, m){
    //     cin >> a;
    //     FOR(j, 0, 3){
    //         cin >> s;
    //     }
    //     cin >> b;

    //     if(mp.find(a)==mp.end() or mp.find(b)==mp.end()){
    //         cout << "Pants on Fire" << endl;
    //     }else if(mp[a]<mp[b]){
    //         cout << "Fact" << endl;
    //     }else if(mp[a]>mp[b]){
    //         cout << "Alternative Fact" << endl;
    //     }else{
    //         cout << "Pants on Fire" << endl;
    //     }
    // }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

