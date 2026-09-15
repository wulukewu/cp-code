#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long

void solve(){
    int xl, yl, xr, yr;
    int x1, y1, x2, y2;
    cin >> xl >> yl >> xr >> yr >> x1 >> y1 >> x2 >> y2;
    // cout << xl << yl << xr << yr << x1 << y1 << x2 << y2 << endl;
    
    double goody1, goody2, goodx3, goodx4;
    
    //{[xl, goody1], [xr, goody2], [goodx3, yl], [goodx4, yr]}
    goody1 = (double) (y2 - y1) / (x2 - x1) *(xl - x1) + y1;
    goody2 = (double) (y2 - y1)/(x2 - x1) * (xr - x1) + y1;
    // cout << goody1 << ' ' << goody2 << endl;
    
    goodx3 = (double)(x2 - x1)/(y2 - y1)*(yl - y1) + x1;
    goodx4 = (double)(x2 - x1)/(y2 - y1)*(yr - y1) + x1;
    // cout << goodx3 << ' ' << goodx4 << endl;

    // bool isver = false;
    // bool ishor = false;

    // if(x1 == x2){
    //     isver = true;
    // }

    // if(y1 == y2){
    //     ishor = true;
    // }
    
    if(x1==x2){
        if(xl<=x1 and x1<=xr){
            if((y1>yr and y2>yr) or (y1<yl and y2<yl)){
                cout << "OK" << endl;
            }else{
                cout << "STOP" << endl;
            }
            return;
        }else{
            cout << "OK" << endl;
            return;
        }
    }else if(y1==y2){
        if(yl<=y1 and y1<=yr){
            if((x1>xr and x2>xr) or (x1<xl and x2<xl)){
                cout << "OK" << endl;
            }else{
                cout << "STOP" << endl;
            }
            return;
        }else{
            cout << "OK" << endl;
            return;
        }
    }else{
        vector<pair<double, double>> fourdot = {{xl, goody1}, {xr, goody2}, {goodx3, yl}, {goodx4, yr}};
        vector<pair<double, double>> dotinseg;
        vector<pair<double, double>> perfectdot;
        
        for(auto u:fourdot){
            if(u.F <= max(x1, x2) and u.F >= min(x1, x2) and u.S <= max(y1, y2) and u.S >= min(y1, y2)){
                dotinseg.PB(u);
            }
        }
        
        for(auto u:dotinseg){
            if(u.F <= max(xl, xr) and u.F >= min(xl, xr) and u.S <= max(yl, yr) and u.S >= min(yl, yr)){
                perfectdot.PB(u);
            }
        }
        
        if(perfectdot.empty()){
            cout << "OK" << endl;
        }else{
            cout << "STOP" << endl;
        }
        
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