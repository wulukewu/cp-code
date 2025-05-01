#include <iostream>
#include <vector>

using namespace std;

signed main(){
    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.size();
    int l2 = s2.size();

    int n = 500;
    vector < vector < int > > arr(l1+1, vector < int > (l2+1, 0));

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }else{
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
    }

    cout << arr[l1][l2];
}