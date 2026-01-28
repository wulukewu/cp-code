// ==================================================
// Problem   : ABC378_C - Repeating
// URL       : https://atcoder.jp/contests/abc378/tasks/abc378_c
// ==================================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> last_seen;
    vector<int> result(n, -1);

    for(int i = 0; i < n; i++) {
        if(last_seen.find(A[i]) != last_seen.end()) {
            result[i] = last_seen[A[i]];
        }
        last_seen[A[i]] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}