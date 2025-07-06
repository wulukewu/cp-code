#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <sstream>

using namespace std;

int main(){
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");

    int n;
    string line;
    vector < int > arr;
    vector < int > brr;

    getline(fcin, line);
    stringstream ss(line);
    while(ss >> n){
        arr.push_back(n);
    }
    getline(fcin, line);
    ss.clear();
    ss.str(line);
    while(ss >> n){
        brr.push_back(n);
    }

    // for(int i: arr){
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for(int i: brr){
    //     cout << i << ' ';
    // }
    // cout << endl;

    vector < int > crr;
    int n1 = arr.size();
    int n2 = brr.size();
    int j = 0;
    for(int i=0; i<n1; i++){
        while(arr[i]>brr[j] and j<n2){
            crr.push_back(brr[j]);
            j++;
        }
        crr.push_back(arr[i]);
    }

    while(j<n2){
        crr.push_back(brr[j]);
        j++;
    }

    for(int i: crr){
        fcout << i << ' ';
    }
}