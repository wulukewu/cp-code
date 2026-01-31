// ==================================================
// Problem   : 105000C - Unknown
// URL       : https://codeforces.com/contest/105000/problem/C
// ==================================================

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>

using namespace std;

int main(){
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");

    int n;
    // cin >> n;
    fcin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        // cin >> arr[i];
        fcin >> arr[i];
    }

    sort(arr.begin(), arr.begin() + n/2);
    // sort(arr.begin() + n/2, arr.end(), greater<int>());
    sort(arr.begin() + n/2, arr.end(), [](int a, int b){
        return a > b;
    });

    for(int i=0; i<n; i++){
        // cout << arr[i] << ' ';
        fcout << arr[i] << ' ';
    }
}