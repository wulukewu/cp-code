#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
 
long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    long long n,m,k;
    cin>>n>>m>>k;
    long long x = k%(2*(n-1));
    long long y = k%(2*(m-1));
    if( x>=n-1 ) x = n*2-x-2;
    if( y>=m-1 ) y = m*2-y-2;
    long long g = gcd(n-1, m-1);
    long long lcm = (n-1)*(m-1)/g;
    long long t = k/(n-1)+k/(m-1)-k/lcm;
    cout<<x+1<<" "<<y+1<<" "<<t<<endl; 
}
 
int main() {
    FASTIO; 
    int tc;
    cin>>tc;
    while(tc--)
        solve();
 
    return 0;
}
