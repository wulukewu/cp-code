#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, pair<int, int>> sum;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = a[i] + a[j];
            if (sum.count(x - s)) {
                auto p = sum[x - s];
                cout << p.first + 1 << ' ' << p.second + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
        for (int j = 0; j < i; j++) {
            sum[a[i] + a[j]] = {j, i};
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
