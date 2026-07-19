#include <iostream>
using namespace std;
typedef long long ll;
const int logX = 32;

int basis[logX];

bool insert_vector(int mask) {
    for (int i = logX - 1; i >= 0; i--) {
        if ((mask & (1 << i)) == 0) continue;
        if (!basis[i]) {
            basis[i] = mask;
            return true;
        }
        mask ^= basis[i];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (insert_vector(x))
            ans *= 2;
    }
    cout << ans << '\n';
    return 0;
}
