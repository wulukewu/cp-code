#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 10000001;
int p1[MAXN], p2[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(p1, -1, sizeof(p1));
    memset(p2, -1, sizeof(p2));
    for (int i = 0; i * i < MAXN; i++)
        for (int j = i; j * j < MAXN; j++) {
            int s = i * i + j * j;
            if (s < MAXN) { p1[s] = i; p2[s] = j; }
        }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            int j = n - i;
            if (p1[i] != -1 && p1[j] != -1) {
                cout << p1[i] << ' ' << p2[i] << ' ' << p1[j] << ' ' << p2[j] << '\n';
                break;
            }
        }
    }
    return 0;
}
