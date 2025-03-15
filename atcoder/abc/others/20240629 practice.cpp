#include <iostream>
using namespace std;

vector <int> arr;

int f(int x){
    if(x == 0) return 1;
    // return f(x/2) + f(x/3);
    return f(x/2)+arr[x-1];
}

int main(){
    int n;
    cin >> n;
    // vector <int> arr(n);
    arr = vector <int> (n);

    for(int i = 0; i < n; i++){
        // arr.push_back(f(i));
        arr[i] = f(i);
        cout << arr[i] << ' ';
    }

    
}