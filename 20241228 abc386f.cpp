#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <math.h>
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int k;
    string s, t;
    cin >> k >> s >> t;

    int ns = s.size();
    int nt = t.size();

    bool det = true;
    if(ns == nt){
        for(int i=0; i<ns; i++){
            if(s[i] != t[i]){
                k--;
            }
            if(k < 0){
                det = false;
                break;
            }
        }
    }else if(abs(ns-nt) <= k){
        int j1=0;
        int j2=0;
        for(int i=0; i<min(ns, nt); i++){
            if(s[i+j1] != t[i+j2]){
                if(ns>nt)j1++;
                else j2++;
                k--;
            }
            if(k < 0){
                det = false;
                break;
            }
        }
    }else{
        det = false;
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
