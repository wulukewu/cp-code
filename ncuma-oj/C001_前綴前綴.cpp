#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < int > arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++){
        arr[i] += arr[i-1];
    }

    for(int i=1; i<=n; i++){
        cout << arr[i];
        if(i!=n){
            cout << ' ';
        }
    }
    cout << endl;

    int q;
    cin >> q;

    int a, b;
    for(int i=0; i<q; i++){
        cin >> a >> b;

        if((arr[b]-arr[a-1])%2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}