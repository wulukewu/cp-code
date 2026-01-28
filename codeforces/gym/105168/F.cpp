// ==================================================
// Problem   : 105168F.cpp - Unknown
// URL       : https://codeforces.com/contest/105168/problem/F.cpp
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
#define FOR(i, a ,b) for(int i = a; i< b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

bool cpm(pair<int,int> a,pair<int,int> b){
    return a.F < b.F;
}

void solve(){
    int n,m,E;
    cin >> n >> m >> E;
    vector < pair<int,int> > up;
    vector < pair<int,int> > down;
    int start,end;
    FOR(i,0,n){
        cin >> start >> end;
        up.PB({start,end});
    }
    sort(ALL(up),cpm);
    FOR(i,0,m){
        cin >> start >> end;
        down.PB({start,end});
    }
    sort(ALL(down),cpm);

    // for(auto i:up) cout << i.F << " " << i.S << endl;
    // cout << endl;
    // for(auto i:down) cout << i.F << " " << i.S << endl;

    int i=0,j=0;
    // cout << i << " " << j << " " << E << endl;
    while(i<n and j<m and E >= 0){
        // cout << "123" << endl;
        if(up[i].S <= down[j].F){
            // cout << 1 << endl;
            i += 1;
        }
        else if(up[i].F >= down[j].S){
            // cout << 2 << endl;
            j += 1;
        }
        else if(up[i].S > down[j].F and up[i].S <= down[j].S and up[i].F <= down[j].F){
            // cout << E << " " << (down[j].F-up[i].S) << endl;
            E += (down[j].F-up[i].S);
            i += 1;
        }
        else if(up[i].S > down[j].F and up[i].S <= down[j].S and up[i].F >  down[j].F){
            // cout << E << " " << (up[i].F-up[i].S) << endl;
            E += (up[i].F-up[i].S);
            i += 1;
        }
        else if(up[i].S > down[j].F and up[i].S >  down[j].S and up[i].F <= down[j].F){
            // cout << E << " " << (down[j].F-down[j].S) << endl;
            E += (down[j].F-down[j].S);
            j += 1;
        }
        else if(up[i].S > down[j].F and up[i].S >  down[j].S and up[i].F <= down[j].S){
            // cout << E << " " << (up[i].F-down[j].S) << endl;
            E += (up[i].F-down[j].S);
            j += 1;
        }
        // else cout << up[i].F << " " << up[i].S << " " << down[j].F << " " << down[j].S << endl;
    }
    if(E >= 0) cout << E << endl;
    else cout << -1 << endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}