#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, aux, to, from);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);

    return 0;
}
