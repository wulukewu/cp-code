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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if(n==1){
        cout << s;
    }else{
        int state = s[0]-'0';
        int count = 1;
        vector < pair<int, int> > arr;
        for(int i=1; i<n; i++){
            if(s[i]-'0'==state){
                count++;
            }else{
                arr.push_back(make_pair(state, count));
                state = 1-state;
                count = 1;
            }
        }
        arr.push_back(make_pair(state, count));

        // for(int i=0; i<arr.size(); i++){
        //     cout << arr[i].first << " " << arr[i].second << endl;
        // }

        int c = 0;
        int si = arr.size();
        int head = 0;
        int idx;
        for(int i=0; i<si; i++){
            if(arr[i].first == 1){
                c++;
            }
            if(c==k){
                idx = i;
                break;
            }
            head += arr[i].second;
        }
        head -= arr[idx-1].second;

        cout << s.substr(0, head);
        for(int i=0; i<arr[idx].second; i++)cout << arr[idx].first;
        for(int i=0; i<arr[idx-1].second; i++)cout << arr[idx-1].first;
        head += arr[idx].second + arr[idx-1].second;
        cout << s.substr(head, n-head);
    }
}
