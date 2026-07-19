#include <iostream>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 直接計算列與行的 XOR 值就是該格的 MEX
                cout << (i ^ j) << (j == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}