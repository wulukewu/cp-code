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
        for(int i=0; i<si; i++){
            if(arr[i].first == 1){
                c++;
            }
            if(c==k-1){
                for(int j=0; j<arr[i].second; j++)cout << arr[i].first;
                i+=2;
                for(int j=0; j<arr[i].second; j++)cout << arr[i].first;
                i--;
                for(int j=0; j<arr[i].second; j++)cout << arr[i].first;
                i++;
            }else{
                for(int j=0; j<arr[i].second; j++)cout << arr[i].first;
            }
        }
    }
}
