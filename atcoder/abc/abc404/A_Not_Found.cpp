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
    string s;
    cin >> s;

    int n = s.size();

    char c = 'a';
    for(int i=0; i<26; i++){
        // cout << c << endl;
        bool det = true;
        for(int j=0; j<n; j++){
            if(c==s[j]){
                det = false;
                break;
            }
        }
        if(det){
            cout << c;
            break;
        }
        c++;
    }
}
