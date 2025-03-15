#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string n;
    cin >> n;

    bool det = true;
    for(int i=0; i < n.length()-1; i++){
        if(n[i] <= n[i+1]){
            det = false;
            break;
        }
    }

    if(det){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
