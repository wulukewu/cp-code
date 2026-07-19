#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in;
int pos[100005];
int n, idx;

void post(int l, int r) {
    if (l > r) return;
    int root = pre[idx++];
    int m = pos[root];
    post(l, m - 1);
    post(m + 1, r);
    cout << in[m] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    idx = 0;
    post(0, n - 1);
    cout << "\n";
    return 0;
}
