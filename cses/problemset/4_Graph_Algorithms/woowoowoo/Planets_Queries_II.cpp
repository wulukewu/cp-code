#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_J = 20; // 2^19 > 200000

int n, q;
vector<int> t;
int up[MAX_J][200005];
vector<int> in_degree;
vector<int> depth_arr;
vector<int> comp_id;
vector<int> cycle_pos;
vector<int> cycle_size;

// 倍增法快速跳躍
int jump(int x, int k) {
    for (int j = 0; j < MAX_J; ++j) {
        if ((k >> j) & 1) {
            x = up[j][x];
        }
    }
    return x;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    t.resize(n + 1);
    in_degree.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        up[0][i] = t[i];
        in_degree[t[i]]++;
    }

    // 1. 預處理倍增表
    for (int j = 1; j < MAX_J; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // 2. 利用拓撲排序（佇列）找出所有的樹枝節點，留下來的就是環
    vector<int> q_nodes;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q_nodes.push_back(i);
        }
    }

    // 用於拓撲排序的指標
    int head = 0;
    while (head < (int)q_nodes.size()) {
        int u = q_nodes[head++];
        int v = t[u];
        in_degree[v]--;
        if (in_degree[v] == 0) {
            q_nodes.push_back(v);
        }
    }

    // 3. 標記環與連通分量
    comp_id.assign(n + 1, 0);
    cycle_pos.assign(n + 1, -1);
    depth_arr.assign(n + 1, 0);
    
    int current_comp = 0;

    for (int i = 1; i <= n; ++i) {
        // 如果 in_degree > 0，代表此點在環上，且還沒被分配連通分量
        if (in_degree[i] > 0 && comp_id[i] == 0) {
            current_comp++;
            int curr = i;
            int pos = 0;
            vector<int> cycle_nodes;
            
            while (comp_id[curr] == 0) {
                comp_id[curr] = current_comp;
                cycle_pos[curr] = pos++;
                cycle_nodes.push_back(curr);
                curr = t[curr];
            }
            
            cycle_size.push_back(pos); // 記錄此環的大小
        }
    }

    // 4. 計算樹枝節點的深度與所屬連通分量（從葉子往環的方向推回去）
    // 逆向遍歷拓撲排序的結果，確保父節點（更靠近環的點）先被計算或後被更新
    for (int i = (int)q_nodes.size() - 1; i >= 0; --i) {
        int u = q_nodes[i];
        int v = t[u];
        depth_arr[u] = depth_arr[v] + 1;
        comp_id[u] = comp_id[v];
    }

    // 5. 回答查詢
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (comp_id[a] != comp_id[b]) {
            cout << "-1\n";
            continue;
        }

        // 情況 1 & 2：b 在環上
        if (cycle_pos[b] != -1) {
            if (cycle_pos[a] != -1) { // a 也在環上
                int c_size = cycle_size[comp_id[a] - 1];
                cout << (cycle_pos[b] - cycle_pos[a] + c_size) % c_size << "\n";
            } else { // a 在樹上，b 在環上
                int root_a = jump(a, depth_arr[a]);
                int c_size = cycle_size[comp_id[a] - 1];
                int ans = depth_arr[a] + (cycle_pos[b] - cycle_pos[root_a] + c_size) % c_size;
                cout << ans << "\n";
            }
        } 
        // 情況 3：b 在樹上
        else {
            if (cycle_pos[a] != -1) { // a 在環上是不可能走到樹上的
                cout << "-1\n";
            } else { // a, b 都在樹上
                if (depth_arr[a] >= depth_arr[b] && jump(a, depth_arr[a] - depth_arr[b]) == b) {
                    cout << depth_arr[a] - depth_arr[b] << "\n";
                } else {
                    cout << "-1\n";
                }
            }
        }
    }

    return 0;
}