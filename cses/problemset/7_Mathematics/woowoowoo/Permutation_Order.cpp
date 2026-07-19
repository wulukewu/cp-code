#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long fact[21];
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    int t;
    cin >> t;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long n, k;
            cin >> n >> k;
            k--;
            vector<int> nums(n);
            for (int i = 0; i < n; i++) nums[i] = i + 1;
            for (int i = 0; i < n; i++) {
                long long f = fact[n - 1 - i];
                int idx = k / f;
                k %= f;
                cout << nums[idx] << " \n"[i == n - 1];
                nums.erase(nums.begin() + idx);
            }
        } else {
            int n;
            cin >> n;
            vector<int> p(n);
            for (int i = 0; i < n; i++) cin >> p[i];
            long long k = 0;
            for (int i = 0; i < n; i++) {
                int smaller = 0;
                for (int j = i + 1; j < n; j++)
                    if (p[j] < p[i]) smaller++;
                k += smaller * fact[n - 1 - i];
            }
            cout << k + 1 << '\n';
        }
    }
    return 0;
}
