#include <bits/stdc++.h>
using namespace std;

struct Elf {
    long long val;
    int id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; i++) {
        cin >> elves[i].val;
        elves[i].id = i + 1;
    }

    sort(elves.begin(), elves.end(), [](const Elf &a, const Elf &b) {
        return a.val < b.val;
    });

    vector<pair<int, int>> ans;

    if (m == 0) {
        long long current_sum = 0;
        for(int i=0; i<n-1; i++) current_sum += elves[i].val;
        
        if(current_sum < elves[n-1].val) {
            cout << -1 << "\n";
            return;
        }

        
        int wasted_count = 0;
        long long boss_hp = elves[n-1].val;

        while(wasted_count < n-1) {
            long long max_attacker_val = elves[n-2].val; 
            if (current_sum - max_attacker_val >= boss_hp) {
                current_sum -= elves[wasted_count].val;
                wasted_count++;
            } else {
                break;
            }
        }

        if (wasted_count > 0) {
            for(int i = 0; i < wasted_count - 1; i++) {
                ans.push_back({elves[i].id, elves[i+1].id});
            }
            ans.push_back({elves[wasted_count-1].id, elves[n-2].id});
        }

        for(int i = wasted_count; i < n - 1; i++) {
            ans.push_back({elves[i].id, elves[n-1].id});
        }

    } else {

        if (2 * m > n) {
            cout << -1 << "\n";
            return;
        }



        int extra_end = n - 2 * m; 
        int victim_start = n - 2 * m;
        

        if (extra_end > 0) {
            for(int i = 0; i < extra_end; i++) {
                if (i == extra_end - 1) {
                    ans.push_back({elves[i].id, elves[victim_start].id});
                } else {
                    ans.push_back({elves[i].id, elves[i+1].id});
                }
            }
        }


        for(int i = 0; i < m; i++) {
            int victim_idx = victim_start + i;
            int survivor_idx = n - m + i;
            ans.push_back({elves[survivor_idx].id, elves[victim_idx].id});
        }
    }

    cout << ans.size() << "\n";
    for(auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}