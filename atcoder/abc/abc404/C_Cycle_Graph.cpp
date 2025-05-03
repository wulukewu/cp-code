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
    int n, m;
    cin >> n >> m;

    if(n!=m){
        cout << "No";
        return 0;
    }

    vector < vector < int > > arr(n);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }

    for(int i=0; i<n; i++){
        if(arr[i].size()!=2){
            cout << "No";
            return 0;
        }
    }

    bool ans = true;
    vector < int > went(n, 0);
    went[0] = 1;
    queue < pair < int, int > > q;
    q.push(make_pair(0, arr[0][0]));
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        q.pop();

        if(went[b]==0){
            went[b] = 1;
        }else if(b==0){
            ans = true;
            break;
        }else{
            ans = false;
        }

        for(int i=0; i<2; i++){
            if(arr[b][i] != a){
                q.push(make_pair(b, arr[b][i]));
            }
        }
    }

    for(int i=0; i<n; i++){
        if(went[i]==0){
            ans = false;
            break;
        }
    }

    if(ans){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
