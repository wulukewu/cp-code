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
#include <stack>
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int n=s.size();

    if(n%2!=0){
        cout << "No";
        return 0;
    }

    stack <char> arr;
    bool det = true;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '<') {
            arr.push(s[i]);
        } else if(s[i] == ')' || s[i] == ']' || s[i] == '>') {
            if(arr.empty() || (s[i] == ')' && arr.top() != '(') || (s[i] == ']' && arr.top() != '[') || (s[i] == '>' && arr.top() != '<')) {
                det = false;
                break;
            } else {
                arr.pop();
            }
        }
    }

    if(det and arr.empty()){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
