// ==================================================
// Problem   : 105000F - Unknown
// URL       : https://codeforces.com/contest/105000/problem/F
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

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        fcin >> arr[i];
    }

    bool det = true;
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                det = false;
                for(int k: arr){
                    fcout << k << ' ';
                }
                fcout << endl;
            }
        }
    }
    
    if(det){
        fcout << 0;
    }
}