// ==================================================
// Problem   : ABC384_C - Perfect Standings
// URL       : https://atcoder.jp/contests/abc384/tasks/abc384_c
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
// #include <fstream>

char ABCDE[5] = {'A', 'B', 'C', 'D', 'E'};
vector<int> scores(5);
vector< pair<int, string> > arr;

void next(string abc, int s, int i) {
    if (i == 5) {
        if (abc == "") {
            return;
        }
        arr.push_back(make_pair(s, abc));
        return;
    }
    
    next(abc, s, i + 1);
    next(abc + ABCDE[i], s + scores[i], i + 1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
    }

    next("", 0, 0);
    // cout << arr.size() << endl;

    // sort(arr.begin(), arr.end());
    // reverse(arr.begin(), arr.end());

    int n = arr.size();
    // for (int i = 0; i < n; i++) {
    //     // cout << arr[i].first << " " << arr[i].second << endl;
    //     cout << arr[i].second << endl;
    // }

    vector<int> score_diff;
    for (int i = 0; i < n; i++) {
        bool det = true;
        int m = score_diff.size();
        for (int j = 0; j < m; j++) {
            if (arr[i].first == score_diff[j]) {
                det = false;
                break;
            }
        }
        if (det) {
            score_diff.push_back(arr[i].first);
        }
    }
    sort(score_diff.begin(), score_diff.end());
    reverse(score_diff.begin(), score_diff.end());
    
    int m = score_diff.size();
    for (int i = 0; i < m; i++) {
        // cout << score_diff[i] << endl;
        vector<string> names;
        for (int j = 0; j < n; j++) {
            if (arr[j].first == score_diff[i]) {
                // cout << arr[j].second << endl;
                names.push_back(arr[j].second);
            }
        }
        sort(names.begin(), names.end());
        int o = names.size();
        for (int k = 0; k < o; k++) {
            cout << names[k] << endl;
        }
    }
}