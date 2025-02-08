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
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    vector < int > A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector < int > B(n);
    for(int i=0; i<n; i++){
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    vector < int > C(n);
    for(int i=0; i<n; i++){
        cin >> C[i];
    }
    sort(C.begin(), C.end());

    priority_queue < pair < int, vector < int > > > que;
    vector < int > arr(3, -1);
    pair < int, vector < int > > t;
    set < vector < int > > went;

    int i=n-1, j=n-1, l=n-1;
    int a, b, c;

    arr[0]=i;
    arr[1]=j;
    arr[2]=l;
    que.push(make_pair(A[i]*B[j] + B[j]*C[l] + C[l]*A[i], arr));
    went.insert(arr);

    while(k>0){
        t = que.top();
        i = t.second[0];
        j = t.second[1];
        l = t.second[2];
        // cout << t.first << endl;
        que.pop();

        if(i-1>=0){
            arr[0]=i-1;
            arr[1]=j;
            arr[2]=l;
            if(went.find(arr)==went.end()){
                que.push(make_pair(A[i-1]*B[j] + B[j]*C[l] + C[l]*A[i-1], arr));
                went.insert(arr);
            }
        }

        if(j-1>=0){
            arr[0]=i;
            arr[1]=j-1;
            arr[2]=l;
            if(went.find(arr)==went.end()){
                que.push(make_pair(A[i]*B[j-1] + B[j-1]*C[l] + C[l]*A[i], arr));
                went.insert(arr);
            }
        }

        if(l-1>=0){
            arr[0]=i;
            arr[1]=j;
            arr[2]=l-1;
            if(went.find(arr)==went.end()){
                que.push(make_pair(A[i]*B[j] + B[j]*C[l-1] + C[l-1]*A[i], arr));
                went.insert(arr);
            }
        }

        k--;
    }

    // t = que.top();
    // i = t.second[0];
    // j = t.second[1];
    // l = t.second[2];
    // cout << i << ' ' << j << ' ' << l << endl;
    cout << t.first << endl;

}
