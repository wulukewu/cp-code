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
    
    int n, t, a;
    cin >> n >> t >> a;

    if(n-t-a > abs(t-a)){
        cout << "No";
    }else{
        cout << "Yes";
    }
}
