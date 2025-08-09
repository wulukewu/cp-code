#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define FOR(i, a , b) for(int i = a; i< a; i< b)

void solve(){
    int n;
    cin >> n;
    int in;
    while(n--){
        cin >> in;
        if(in == 1) in += 7;
        cout << in-1 << endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}