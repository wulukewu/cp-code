#include <iostream>
#include <vector>

using namespace std;

int main(){
    int l1, l2;
    string s1, s2;
    while(cin >> s1){
        cin >> s2;

        l1 = s1.size();
        l2 = s2.size();

        vector < vector < int > > arr(l1+1, vector < int > (l2+1, 0));
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s1[i-1]==s2[j-1]){
                    arr[i][j] = arr[i-1][j-1] + 1;
                }else{
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }

        // for(int i=0; i<=l1; i++){
        //     for(int j=0; j<=l2; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        cout << arr[l1][l2] << endl;
    }
}