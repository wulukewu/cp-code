#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    struct Event { int time, type, idx; };
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 0, i});
        events.push_back({b, 1, i});
    }
    sort(events.begin(), events.end(), [](Event &x, Event &y) {
        if (x.time != y.time) return x.time < y.time;
        return x.type < y.type;
    });
    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> free_rooms;
    int next_room = 1;
    for (auto &e : events) {
        if (e.type == 0) {
            if (free_rooms.empty()) {
                ans[e.idx] = next_room++;
            } else {
                ans[e.idx] = free_rooms.top();
                free_rooms.pop();
            }
        } else {
            free_rooms.push(ans[e.idx]);
        }
    }
    cout << next_room - 1 << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
