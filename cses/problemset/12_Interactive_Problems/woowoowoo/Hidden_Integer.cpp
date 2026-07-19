#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        char op;
        cin >> op;
        if (op == '<') r = mid - 1;
        else l = mid;
    }

    cout << "= " << l << endl;
    return 0;
}
