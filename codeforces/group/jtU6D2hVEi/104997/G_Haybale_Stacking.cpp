#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector < int > arr(n, 0);
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        arr[a-1]++;
        arr[b]--;
    }

    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
}