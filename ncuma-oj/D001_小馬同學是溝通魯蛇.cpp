#include <iostream>
#include <vector>
#include <set>

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    vector < set < int > > arr(n);

    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        a--;
        b--;

        arr[a].insert(b);
        arr[b].insert(a);
    }    

    for(int i=0; i<n; i++){
        for(auto j = arr[i].begin(); j != arr[i].end(); j++){
            if (j != arr[i].begin()) cout << ' ';
            cout << *j + 1;
        }
        cout << endl;
    }
}