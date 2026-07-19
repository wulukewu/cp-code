#include <iostream>
#include <string>

using namespace std;

string board[8];
int col[8], diag1[15], diag2[15];
int ans;

void dfs(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[r][c] == '*') continue;
        if (col[c] || diag1[r + c] || diag2[r - c + 7]) continue;
        col[c] = diag1[r + c] = diag2[r - c + 7] = 1;
        dfs(r + 1);
        col[c] = diag1[r + c] = diag2[r - c + 7] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++) cin >> board[i];

    dfs(0);
    cout << ans << "\n";

    return 0;
}
