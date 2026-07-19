#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<bitset<3000>> v(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '1') v[i].set(j);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            long long cnt = (v[i] & v[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    cout << ans << "
";
    return 0;
}
