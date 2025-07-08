#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector < int > arr;

    int n;
    while(cin >> n){
        arr.push_back(n);
    }

    n = arr.size();

    vector < int > brr(101, 0);
    for(int i=0; i<n; i++){
        brr[arr[i]]++;
    }

    for(int i=0; i<=100; i++){
        for(int j=0; j<brr[i]; j++){
            cout << i << ' ';
        }
    }
}