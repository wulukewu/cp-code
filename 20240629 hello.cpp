// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>

using namespace std;
int n;
vector <pair<int, int> > arr;

int m(int a){
    return a + arr[a].second;
}

int main(){
    // int arr[10];
    // vector <pair<int, int> > arr(15);
    n = 15;
    arr = vector <pair<int, int> >(n);
    for(int i = 0; i < 15; i++){
        arr[i].first = 15-i;
        arr[i].second = i;
        // for(int j = 0; j < 3; j++){
        //     arr[i][j] = i * j;
        // }
        // arr[i] = i;
        // arr.push_back(i);
        // cout << "Hello World " << endl;
    }

    // reverse(arr.begin(), arr.end());

    for(int i = 0; i < 15; i++){
        // for(int j = 0; j < 3; j++) cout << arr[i][j] << " ";
        // cout << endl;
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    // while(true){
    //     continue;
    // }
    // int j = arr.size();
    // for(int i = 0; i < j; i++){
    //     cout << arr[i];
    // }
    // char x = 'A' + 1;
    // int y = x - 0;
    // char z = x + 1;
    // cout << x << y << z;
    cout << m(3);
}