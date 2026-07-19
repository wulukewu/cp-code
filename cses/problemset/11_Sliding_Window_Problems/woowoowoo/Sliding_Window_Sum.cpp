#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) arr[i] = (1LL * a * arr[i - 1] + b) % c;
    long long sum = 0, ans = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    ans ^= sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        ans ^= sum;
    }
    cout << ans << "\n";
    return 0;
}
