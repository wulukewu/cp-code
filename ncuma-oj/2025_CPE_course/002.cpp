#include <iostream>

using namespace std;

signed main(){
    int a, b;
    while(cin >> a){
        cin >> b;

        int ans = 0;
        for(int n=a; n<=b; n++){
            bool is_prime = true;
            for(int i=2; i*i<=n; i++){
                if(n%i==0){
                    is_prime = false;
                    break;
                }
            }
            if(is_prime) ans++;
        }
        cout << ans << endl;
    }
}