#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Basis {
    static const int BITs = 60;
    ll basis[BITs + 1] = {};
    int comp_sz = 0;
    void insert(ll msk) {
        for (int i = BITs; i >= 0; i--) {
            if (!(msk >> i & 1)) continue;
            if (!basis[i]) {
                comp_sz++;
                basis[i] = msk;
                return;
            }
            msk ^= basis[i];
        }
    }
    ll get(ll k, int n) {
        ll mult = 1LL << (n - comp_sz);
        ll k_unique = (k + mult - 1) / mult;
        vector<pair<int, ll>> vec;
        for (int i = BITs; i >= 0; i--)
            if (basis[i])
                vec.push_back({i, basis[i]});
        int m = (int)vec.size();
        ll rem = k_unique;
        ll x = 0;
        for (int j = 0; j < m; j++) {
            int lead = vec[j].first;
            ll b = vec[j].second;
            ll half = 1LL << (m - j - 1);
            if (((x >> lead) & 1LL) == 0) {
                if (rem > half) {
                    rem -= half;
                    x ^= b;
                }
            } else {
                if (rem <= half) {
                    x ^= b;
                } else {
                    rem -= half;
                }
            }
        }
        return x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Basis bs;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bs.insert(x);
    }
    for (int i = 1; i <= k; i++)
        cout << bs.get(i, n) << " ";
    cout << '\n';
    return 0;
}
