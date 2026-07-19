#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s(n, '0');
    for (int i = 0; i < n; i++) {
        s[i] = '0';
        cout << "? " << s << endl;
        string res;
        cin >> res;
        if (res == "0" || res == "no") {
            s[i] = '1';
            cout << "? " << s << endl;
            cin >> res;
            if (res == "0" || res == "no") {
                cout << "! " << s << endl;
                return 0;
            }
        }
    }

    cout << "! " << s << endl;
    return 0;
}
