#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int a, b, c;
    // a = ((xa-xb)**2 + (ya-yb)**2)**(1/2);
    // b = ((xc-xb)**2 + (yc-yb)**2)**(1/2);
    // c = ((xc-xa)**2 + (yc-ya)**2)**(1/2);
    a = pow(xa-xb, 2) + pow(ya-yb, 2);
    b = pow(xb-xc, 2) + pow(yb-yc, 2);
    c = pow(xc-xa, 2) + pow(yc-ya, 2);
    // cout << a << b << c << endl;

    vector <int> arr(3,-1);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    sort(arr.begin(), arr.end());

    if(arr[0]+arr[1]==arr[2]){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
