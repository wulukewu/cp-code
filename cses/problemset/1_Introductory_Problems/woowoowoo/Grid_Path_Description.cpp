#include <iostream>
#include <string>

using namespace std;

string s;
bool vis[9][9];
int ans;

void dfs(int x, int y, int idx) {
    if (x == 7 && y == 1) {
        if (idx == 48) ans++;
        return;
    }

    if (idx == 48) return;

    if (vis[x][y + 1] && vis[x][y - 1] && !vis[x - 1][y] && !vis[x + 1][y]) return;
    if (vis[x + 1][y] && vis[x - 1][y] && !vis[x][y + 1] && !vis[x][y - 1]) return;

    char c = s[idx];
    vis[x][y] = true;

    if (c == 'U' || c == '?') {
        if (!vis[x - 1][y]) dfs(x - 1, y, idx + 1);
    }
    if (c == 'D' || c == '?') {
        if (!vis[x + 1][y]) dfs(x + 1, y, idx + 1);
    }
    if (c == 'L' || c == '?') {
        if (!vis[x][y - 1]) dfs(x, y - 1, idx + 1);
    }
    if (c == 'R' || c == '?') {
        if (!vis[x][y + 1]) dfs(x, y + 1, idx + 1);
    }

    vis[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i = 0; i < 9; i++) {
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
    }

    dfs(1, 1, 0);
    cout << ans << "\n";

    return 0;
}
