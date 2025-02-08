#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < pair <int, int> > A(n);
    for(int i=0; i<n; i++){
        cin >> A[i].first;
        A[i].second = i+1;
    }

    sort(A.begin(), A.end());

    // for(int i=0; i<n; i++){
    //     cout << A[i].first << ' ' << A[i].second << endl;
    // }

    cout << A[n-2].second;

}
