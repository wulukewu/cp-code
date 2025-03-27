#include <iostream>
#include <math.h>

using namespace std;

signed solve(){
    long long n;
    cin >> n;
    
    bool det = true;
    for(long long i=2; i<=pow(n, .5); i++){
        if(n%i==0){
            det = false;
            break;
        }
    }

    if(det){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;

}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}