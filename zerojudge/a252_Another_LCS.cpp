// ==================================================
// Problem   : ZeroJudge A252 - Another LCS
// URL       : https://zerojudge.tw/ShowProblem?problemid=a252
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();

    vector < vector < vector < int > > > arr(l1+1, vector < vector < int > > (l2+1, vector < int > (l3+1, 0)));
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            for(int k=1; k<=l3; k++){
                if(s1[i-1]==s2[j-1] and s2[j-1]==s3[k-1]){
                    arr[i][j][k] = arr[i-1][j-1][k-1] + 1;
                }else{
                    arr[i][j][k] = max(max(arr[i-1][j][k], arr[i][j-1][k]), arr[i][j][k-1]);
                }
            }
        }
    }

    // for(int i=0; i<=l1; i++){
    //     for(int j=0; j<=l2; j++){
    //         for(int k=0; k<=l3; k++){
    //             cout << arr[i][j][k] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }

    cout << arr[l1][l2][l3];
}