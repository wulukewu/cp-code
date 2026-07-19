#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    long long reachable = 0;
    for (int v : x) {
        if (v > reachable + 1) break;
        reachable += v;
    }
    cout << reachable + 1 << '\n';
    return 0;
}
