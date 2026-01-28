// ==================================================
// Problem   : jtU6D2hVEiK - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/K
// ==================================================

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;

int main(){
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");

    int n;
    fcin >> n;

    int a, b;
    vector < pair < int, int > > arr(n);
    for(int i=0; i<n; i++){
        fcin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    sort(arr.begin(), arr.end(), [](pair < int, int > p1, pair < int, int > p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }else{
            return p1.second > p2.second;
        }
    });

    for(auto i: arr){
        fcout << i.first << ' ' << i.second << endl;
    }
}