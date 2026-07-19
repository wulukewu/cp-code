#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    int distinct = 0;
    for (int i = 0; i < k; i++) {
        if (freq[a[i]]++ == 0) distinct++;
    }
    cout << distinct;
    for (int i = k; i < n; i++) {
        if (--freq[a[i - k]] == 0) distinct--;
        if (freq[a[i]]++ == 0) distinct++;
        cout << " " << distinct;
    }
    cout << "\n";
    return 0;
}
