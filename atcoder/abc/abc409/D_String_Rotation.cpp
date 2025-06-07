#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        for(int i=0; i<n-1; i++){
            if(s[i]>s[i+1]){
                while(i<n-1 and s[i] >= s[i+1]){
                    swap(s[i], s[i+1]);
                    i++;
                }
                break;
            }
        }

        cout << s << endl;
    }
}
