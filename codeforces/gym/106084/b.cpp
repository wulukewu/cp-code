#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    int a, b;
    bool aisprime = true;
    bool bisprime = true;
    cin >> a >> b;

    for(int i = 2; i*i <= a; i++){
        if(a % i == 0){
            aisprime = false;
            break;
        }
    }

    for(int i = 2; i*i <= b; i++){
        if(b % i == 0){
            bisprime = false;
            break;
        }
    }

    if(a == 2){
        aisprime = true;
    }

    if(b == 2){
        bisprime = true;
    }

    if(a == 1){
        aisprime = false;
    }

    if(b == 1){
        bisprime = false;
    }

    if(aisprime and bisprime and a+2 == b){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}