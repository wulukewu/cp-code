#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    int ch[2];
    Trie() { ch[0] = ch[1] = -1; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Trie> trie;
    trie.emplace_back();

    auto insert = [&](int x) {
        int v = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (trie[v].ch[bit] == -1) {
                trie[v].ch[bit] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].ch[bit];
        }
    };

    auto query = [&](int x) {
        int v = 0, res = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (trie[v].ch[bit ^ 1] != -1) {
                res |= (1 << b);
                v = trie[v].ch[bit ^ 1];
            } else {
                v = trie[v].ch[bit];
            }
        }
        return res;
    };

    insert(0);
    int pref = 0, ans = 0;
    for (int x : a) {
        pref ^= x;
        ans = max(ans, query(pref));
        insert(pref);
    }

    cout << ans << "\n";
    return 0;
}
