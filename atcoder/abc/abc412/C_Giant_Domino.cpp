// ==================================================
// Problem   : ABC412_C - Giant Domino
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc412/tasks/abc412_c
// ==================================================

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

int solve(){
    int n;
    cin >> n;

    vector < int > s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    int first = s[0];
    int last = s[n-1];

    sort(s.begin(), s.end());
    int first_idx = -1;
    int last_idx = -1;
    for(int i=0; i<n; i++){
        if(s[i]==first) first_idx = i;
        else if(s[i]==last) last_idx = i;
    }
    // cout << first_idx << ' ' << last_idx << endl;
    // for(int i=first_idx; i<=last_idx; i++){
    //     cout << s[i] << ' ';
    // }
    // cout << endl;

    for(int i=first_idx; i<last_idx; i++){
        if(s[i]*2<s[i+1]){
            return -1;
        }
    }

    int past = s[first_idx];
    stack < int > st;
    st.push(first_idx);
    for(int i=first_idx+1; i<=last_idx; i++){
        if(past*2<s[i]){
            // if(i-1==st.top()){
            //     // cout << -1 << endl;
            //     return -1;
            // }
            st.push(i-1);
            past = s[i-1];
        }
    }

    // cout << "past: " << past << endl;

    if(s[last_idx] > past*2){
        // cout << -1 << endl;
        return -1;
    }else{
        // cout << st.size()+1 << endl;
        return st.size()+1;
    }

    // while(!st.empty()){
    //     cout << st.top() << ' ';
    //     st.pop();
    // }
    // cout << endl;

    // queue < int > q;
    // q.push(0);

    // sort(s.begin(), s.end());
    // // for(int i=0; i<n; i++){
    // //     cout << s[i] << ' ';
    // // }
    // // cout << endl;

    // int past = s[0];
    // for(int i=2; i<n; i++){
    //     if(past*2 < s[i]){
    //         q.push(i-1);
    //         past = s[i-1];
    //     }
    // }
    // if(s[n-1] <= past*2){
    //     q.push(n-1);
    // }

    // int m = 0;
    // bool find_first = false;
    // bool find_last = false;
    // while(!q.empty()){
    //     cout << q.front() << ' ';
    //     if(s[q.front()]==first){
    //         find_first = true;
    //     }else if(s[q.front()]==last){
    //         find_last = true;
    //         m++;
    //         break;
    //     }
    //     if(find_first and !find_last){
    //         m++;
    //     }
    //     q.pop();
    // }
    // cout << endl;
    // cout << q.front() << endl;

    // cout << find_first << ' ' << find_last << endl;
    // if(find_first and find_last){
    //     cout << m << endl;
    // }else{
    //     cout << -1 << endl;
    // }
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}
