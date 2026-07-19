#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << endl;
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    cout << "! " << a[k - 1] << endl;

    return 0;
}
