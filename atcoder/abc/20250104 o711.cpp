#include <iostream>
#include <vector>
using namespace std;
#include <fstream>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int w1, w2, h1, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    

}