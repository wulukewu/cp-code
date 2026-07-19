#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        long long k;
        cin >> k;

        long long len = 1, count = 9, start = 1;
        while (k > len * count) {
            k -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (k - 1) / len;
        int pos = (k - 1) % len;

        string s = to_string(num);
        cout << s[pos] << "\n";
    }

    return 0;
}
