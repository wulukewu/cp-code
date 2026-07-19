#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << "? " << a[j] << " " << a[j + 1] << endl;
            char res;
            cin >> res;
            if (res == '>') swap(a[j], a[j + 1]);
        }
    }

    cout << "!";
    for (int x : a) cout << " " << x;
    cout << endl;

    return 0;
}
