#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) arr[i] = (1LL * a * arr[i - 1] + b) % c;
    deque<int> dq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
        if (i >= k - 1) ans ^= arr[dq.front()];
    }
    cout << ans << "\n";
    return 0;
}
