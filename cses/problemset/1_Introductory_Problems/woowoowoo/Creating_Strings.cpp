#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int count = 0;
    string temp = s;
    do {
        count++;
    } while (next_permutation(temp.begin(), temp.end()));

    cout << count << "\n";
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
