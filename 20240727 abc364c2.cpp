#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, X, Y;
    cin >> n >> X >> Y;

    vector <int> A(n,-1);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector <int> B(n,-1);
    for(int i=0; i<n; i++){
        cin >> B[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << A[i] << ' ';
    // }
    // for(int i=0; i<n; i++){
    //     cout << B[i] << ' ';
    // }
    // cout << endl;

    vector < pair <int, int> > AB(n);
    for(int i=0; i<n; i++){
        AB[i].first = A[i];
        AB[i].second = B[i];
    }
    sort(AB.begin(), AB.end());

    // for(int i=0; i<n; i++){
    //     cout << AB[i].first << ' ' << AB[i].second << endl;
    // }

    int a = 0;
    int b = 0;
    int mn = n;
    for(int i=0; i<n; i++){
        a += AB[n-i-1].first;
        b += AB[n-i-1].second;
        if(a > X or b > Y){
            // cout << i + 1;
            mn = i + 1;
            break;
        }
    }

    vector < pair <int, int> > BA(n);
    for(int i=0; i<n; i++){
        BA[i].first = B[i];
        BA[i].second = A[i];
    }
    sort(BA.begin(), BA.end());

    // for(int i=0; i<n; i++){
    //     cout << BA[i].first << ' ' << BA[i].second << endl;
    // }

    a = 0;
    b = 0;
    for(int i=0; i<n; i++){
        a += BA[n-i-1].first;
        b += BA[n-i-1].second;
        if(a > Y or b > X){
            // cout << i + 1;
            mn = min(mn, i + 1);
            break;
        }
    }

    cout << mn;

}
