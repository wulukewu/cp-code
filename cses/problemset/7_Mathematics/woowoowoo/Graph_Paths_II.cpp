#include <iostream>
#include <vector>

using namespace std;

// 設定無窮大。最長路徑可能為 k * max(c) = 10^9 * 10^9 = 10^18
// 所以 INF 必須大於 10^18。這裡設定為 2e18，
// 且保證 INF + INF = 4e18 不會超過 long long 的上限 (約 9.22e18)
const long long INF = 2e18;

typedef vector<vector<long long>> Matrix;

// 重新定義的矩陣乘法 (Min-Plus Algebra)
Matrix multiply(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            // 如果連不到中繼點 k，就直接跳過，這是一個重要的小優化
            if (A[i][k] == INF) continue; 
            for (int j = 0; j < n; ++j) {
                if (B[k][j] == INF) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

// 矩陣快速冪
Matrix power(Matrix A, long long p, int n) {
    // 建立 Min-Plus 代數下的「單位矩陣」
    Matrix res(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 0; // 走 0 步停留在原地的成本為 0
    }
    
    // 經典的二進位快速冪算法
    while (p > 0) {
        if (p & 1) {
            res = multiply(res, A, n);
        }
        A = multiply(A, A, n);
        p >>= 1;
    }
    return res;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    if (!(cin >> n >> m >> k)) return 0;

    // 建立 0-based 索引的鄰接矩陣
    Matrix adj(n, vector<long long>(n, INF));
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        --u; --v; // 轉換為 0-based
        adj[u][v] = min(adj[u][v], c); // 處理重邊 (Multiple Edges)
    }

    // 求出 adj 的 k 次方
    Matrix res = power(adj, k, n);

    // 輸出答案 (0 到 n-1)
    if (res[0][n - 1] == INF) {
        cout << -1 << "\n";
    } else {
        cout << res[0][n - 1] << "\n";
    }

    return 0;
}