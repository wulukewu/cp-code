#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector <int> A(n, -1);
    vector <int> W(n, -1);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> W[i];
    }

    vector <vector <int> > arr(n);
    for(int i = 0; i < n; i++){
        arr[A[i]-1].push_back(W[i]);
    }

    int s = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].size() > 1){
            int x = arr[i].size();
            sort(arr[i].begin(), arr[i].end());
            for(int j = 0; j < x-1; j++){
                s += arr[i][j];
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < arr[i].size(); j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << s;
}
