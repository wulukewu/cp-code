#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cnt[26] = {};
    for (char c : s) cnt[c - 'A']++;

    int odd = 0;
    char mid = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) {
            odd++;
            mid = 'A' + i;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string half;
    for (int i = 0; i < 26; i++) {
        half.append(cnt[i] / 2, 'A' + i);
    }

    cout << half;
    if (mid) cout << mid;
    for (int i = half.size() - 1; i >= 0; i--) cout << half[i];
    cout << "\n";

    return 0;
}
