#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i + 1;

    for (int i = n - 1; i > 0; i--) {
        int idx = -1;
        for (int j = 0; j <= i; j++) {
            cout << "? " << p[j] << " " << p[i] << endl;
            char res;
            cin >> res;
            if (res == '>') {
                idx = j;
                break;
            }
        }
        if (idx >= 0) {
            swap(p[idx], p[i]);
        }
    }

    cout << "!";
    for (int x : p) cout << " " << x;
    cout << endl;

    return 0;
}
