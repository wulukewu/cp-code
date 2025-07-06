#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector < int > arr;

    int n;
    while(cin >> n){
        arr.push_back(n);
    }

    sort(arr.begin(), arr.end());

    for(int i: arr){
        cout << i << ' ';
    }
}