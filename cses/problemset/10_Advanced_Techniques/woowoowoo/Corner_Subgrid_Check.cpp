#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<bool> ans(k, false);
    for (int c = 0; c < k; c++) {
        bitset<3000> prev;
        for (int i = 0; i < n; i++) {
            bitset<3000> cur;
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 'A' + c) cur.set(j);
            if ((prev & cur).count() >= 2) { ans[c] = true; break; }
            if (cur.any()) prev |= cur;
        }
    }
    for (int c = 0; c < k; c++) cout << (ans[c] ? "YES" : "NO") << "
";
    return 0;
}
