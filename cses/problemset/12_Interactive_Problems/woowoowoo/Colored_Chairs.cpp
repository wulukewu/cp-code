#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << endl;
        cin >> a[i];
    }

    cout << "!";
    for (int x : a) cout << " " << x;
    cout << endl;

    return 0;
}
