#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 儲存每個山/區間的資訊
struct Range {
    int h;        // 高度
    int size;     // 這個區間包含多少座山
    int pathlen;  // 以這個區間內某座山為起點/終點的最大可訪問山數
};

int main() {
    // 提升 I/O 速度，適合 2 * 10^5 等級的測資
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    vector<int> indices(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].h;
        ranges[i].size = 1;
        ranges[i].pathlen = 1;
        indices[i] = i;
    }

    // 依照高度從小到大排序索引
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return ranges[i].h < ranges[j].h;
    });

    int max_ans = 0;

    // 從矮到高處理每一座山
    for (int idx : indices) {
        int h = ranges[idx].h;
        int current_path = ranges[idx].pathlen;

        // 1. 向左合併比自己矮的區間
        int li = idx;
        while (li > 0 && ranges[li - 1].h < h) {
            int left_neighbor = li - 1;
            current_path = max(current_path, ranges[left_neighbor].pathlen + 1);
            li -= ranges[left_neighbor].size; // 直接跨過該矮山區間
        }

        // 2. 向右合併比自己矮的區間
        int ri = idx;
        while (ri < n - 1 && ranges[ri + 1].h < h) {
            int right_neighbor = ri + 1;
            current_path = max(current_path, ranges[right_neighbor].pathlen + 1);
            ri += ranges[right_neighbor].size; // 直接跨過該矮山區間
        }

        // 更新合併後新大區間的邊界資訊
        int total_size = ri - li + 1;
        ranges[li].size = total_size;
        ranges[li].pathlen = current_path;
        ranges[li].h = h;

        ranges[ri].size = total_size;
        ranges[ri].pathlen = current_path;
        ranges[ri].h = h;

        max_ans = max(max_ans, current_path);
    }

    cout << max_ans << "\n";

    return 0;
}