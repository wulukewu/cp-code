#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int fullMask = (1 << k) - 1;
    long long ans = 0;
    for (int top = 0; top < n; top++) {
        vector<int> colMask(n, 0);
        for (int bot = top; bot < n; bot++) {
            for (int j = 0; j < n; j++)
                colMask[j] |= (1 << (grid[bot][j] - 'A'));
            int r = -1;
            int curMask = 0;
            int cnt[26] = {0};
            for (int l = 0; l < n; l++) {
                while (r + 1 < n && curMask != fullMask) {
                    r++;
                    int m = colMask[r];
                    for (int c = 0; c < k; c++)
                        if (m & (1 << c)) {
                            if (cnt[c] == 0) curMask |= (1 << c);
                            cnt[c]++;
                        }
                }
                if (curMask == fullMask) ans += (n - r);
                int m = colMask[l];
                for (int c = 0; c < k; c++)
                    if (m & (1 << c)) {
                        cnt[c]--;
                        if (cnt[c] == 0) curMask &= ~(1 << c);
                    }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
