#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());
    long long time = 0, ans = 0;
    for (auto &t : tasks) {
        time += t.first;
        ans += t.second - time;
    }
    cout << ans << '\n';
    return 0;
}
