#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> code(n - 2);
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; i++) {
        cin >> code[i];
        code[i]--;
        degree[code[i]]++;
    }
    int ptr = 0;
    while (ptr < n && degree[ptr] != 1) ptr++;
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int v = code[i];
        int a = leaf + 1, b = v + 1;
        if (a > b) swap(a, b);
        cout << a << " " << b << "\n";
        degree[leaf]--;
        degree[v]--;
        if (degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while (ptr < n && degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }
    int a = leaf + 1;
    ptr++;
    while (ptr < n && degree[ptr] != 1) ptr++;
    int b = ptr + 1;
    if (a > b) swap(a, b);
    cout << a << " " << b << "\n";
    return 0;
}
