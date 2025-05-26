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

    int ans = s.size();
    for(int i=0; i<s.size()-1; i++){
        // if(s[i+1]-s[i]<=0){
        //     ans += s[i+1] - s[i];
        // }else{
        //     ans += s[i] - s[i+1] + 10;
        // }
        ans += (s[i]-s[i+1]+10) % 10;
    }
    ans += s[s.size()-1] - '0';

    cout << ans;

    // string s;
    // cin >> s;

    // int n = 0;
    // int x;
    // while(s.size()>0){
    //     x = s[s.size()-1] - '0';
    //     // cout << x << endl;
    //     n += x + 1;
    //     s.pop_back();
    //     for(int i=0; i<s.size(); i++){
    //         s[i] = '0' + (((s[i] - '0') + 10 - x) % 10);
    //     }
    //     // cout << s << endl;
    // }

    // cout << n;

    // int s;
    // cin >> s;

    // int n = 0;
    // int x;
    // while(s>0){
    //     x = s % 10;
    //     n += x + 1;
    //     s /= 10;
    //     if(s==0) break;
    //     string ss = to_string(s);
    //     // cout << ss << endl;
    //     s = 0;
    //     for(int i=0; i<ss.size(); i++){
    //         s *= 10;
    //         s += ((ss[i] - '0') + 10 - x) % 10;
    //     }
    //     cout << s << endl;
    // }

    // cout << n;
}
