// ==================================================
// Problem   : 104997E - Unknown
// URL       : https://codeforces.com/contest/104997/problem/E
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector < int > arr(n, 0);
    int a;
    while(cin >> a){
        arr[a-1]++;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
}