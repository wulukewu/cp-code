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
// #include <fstream>

signed solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    // cout << s << ' ';

    string ss = s;
    reverse(ss.begin(), ss.end());

    for(int i=0; i<n; i++){
        if(s<ss){
            cout << "YES" << endl;
        }else if(k==0){
            cout << "NO" << endl;
        }else if(s==ss){
            bool det = true;
            for(int t=0; t<n-1; t++){
                if(s[t]!=s[t+1]){
                    det = false;
                    break;
                }
            }
            if(det){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else{
            // cout << "-" << endl;
            if(s[i]>s[n-1-i]){
                swap(s[i], s[n-1-i]);
                swap(ss[i], ss[n-1-i]);
                k--;
            }
            continue;
        }
        break;
    }
    
    // int j;
    // for(int i=0; i<n; i++){
    //     j = n-1-i;

    //     ss = s;
    //     reverse(ss.begin(), ss.end());

    //     if(s<ss){
    //         cout << "YES" << endl;
    //         break;
    //     }else if(k==0){
    //         cout << "NO" << endl;
    //         break;
    //     }else if(i==j){
    //         bool det = true;
    //         for(int t=0; t<n-1; t++){
    //             if(s[t]!=s[t+1]){
    //                 det = false;
    //                 break;
    //             }
    //         }
    //         if(det){
    //             cout << "NO" << endl;
    //         }else{
    //             cout << "YES" << endl;
    //         }
    //         break;
    //     }else{
    //         if(s[i]>s[j]){
    //             // swap(s[i], s[j]);
    //             // k--;
    //             cout << "YES" << endl;
    //             break;
    //         }
    //     }
    // }

    // while(true){
    //     if(s<ss){
    //         cout << "YES" << endl;
    //         break;
    //     }else if(k==0){
    //         // cout << "NO" << endl;
    //         cout << "NO" << i << ' ' << j << endl;
    //         break;
    //     }else if(i==j){
    //         cout << "YES" << endl;
    //         break;
    //     }else{
    //         // cout << "-" << endl;
    //         if(s[i]!=s[j]){
    //             swap(s[i], s[j]);
    //             k--;
    //         }
    //         i++;
    //         j--;
    //         if(i>j){
    //             // cout << "NO" << endl;
    //             cout << "NO" << i << j << endl;
    //             break;
    //         }
    //     }
    // }

}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        solve();
    }
}
