// ==================================================
// Problem   : CPE 12442 - Forwarding Emails
// URL       : https://onlinejudge.org/external/124/12442.pdf
// ==================================================

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

set < int > num;
map < int, int > arr;
map < int, int > brr;
set < int > went;

int dfs(int x){
    if(arr.find(x)!=arr.end() and went.find(x)==went.end()){
        went.insert(x);
        return 1 + dfs(arr[x]);
    }else{
        return 0;
    }
}

int main(){
    int t;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        int n;
        cin >> n;

        num.clear();
        arr.clear();
        brr.clear();
        went.clear();

        int u, v;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            arr.insert(make_pair(u, v));
            brr.insert(make_pair(v, u));
            if(num.find(u) == num.end()){
                num.insert(u);
            }
            if(num.find(v) == num.end()){
                num.insert(v);
            }
        }

        // for(auto i: arr){
        //     cout << i.first << ' ' << i.second << endl;
        // }
        // cout << '-' << endl;
        // for(auto i: brr){
        //     cout << i.first << ' ' << i.second << endl;
        // }
        // cout << '-' << endl;
        // cout << "num: ";
        // for(auto i: num){
        //     cout << i << ' ';
        // }
        // cout << endl << '-' << endl;

        int ans = -1;
        int max_len = 0;
        for(auto i: num){
            if(brr.find(i) == brr.end()){
                int a = dfs(i);
                // cout << a << endl;
                if(a>max_len or ans==-1 or (a==max_len and i<ans)){
                    max_len = a;
                    ans = i;
                }
            }
        }
        for(auto i: num){
            if(brr.find(i)!=brr.end() and went.find(i)==went.end()){
                int a = dfs(i);
                // cout << a << endl;
                if(a>max_len or ans==-1 or (a==max_len and i<ans)){
                    max_len = a;
                    ans = i;
                }
            }
        }

        // cout << "went: ";
        // for(auto i: went){
        //     cout << i << ' ';
        // }
        // cout << endl;
        // cout << '-' << endl;

        cout << "Case " << tt << ": " << ans << endl;

        // cout << "--" << endl;
    }
}

// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// vector < int > brr;

// int dfs(vector < vector < int > > arr, vector < int > went, int k){
//     // cout << "call dfs" << endl;
//     int y = 0;
//     int yy;

//     for(auto i: arr[k]){
//         if(went[i]){
//             continue;
//         }else if(brr[i] != -1){
//             yy = brr[i];
//         }else{
//             went[i] = 1;
//             yy = dfs(arr, went, i);
//             went[i] = 0;
//         }

//         if(yy>y){
//             y = yy;
//         }
//     }

//     return y+1;
// }

// int main(){
//     int t;
//     cin >> t;

//     for(int case_t=0; case_t<t; case_t++){
//         int n;
//         cin >> n;

//         vector < vector < int > > arr(n);
//         int u, v;
//         for(int i=0; i<n; i++){
//             cin >> u >> v;
//             arr[u-1].push_back(v-1);
//         }

//         // for(int i=0; i<n; i++){
//         //     for(int j=0; j<arr[i].size(); j++){
//         //         cout << arr[i][j] << ' ';
//         //     }
//         //     cout << endl;
//         // }

//         vector < int > l;
//         int last, l_size;
//         brr = vector < int > (n, -1);
//         for(int i=0; i<n; i++){
//             stack < vector < int > > togo;
//             togo.push(vector < int > (1, i));
//             while(!togo.empty()){
//                 l = togo.top();
//                 togo.pop();

//                 last = l[l.size()-1];
//                 l_size = l.size();
//                 if(brr[last] != -1) continue;

//                 if(last == i and l_size > 1){
//                     for(int j=0; j<l_size; j++){
//                         brr[l[j]] = l_size-1;
//                     }
//                 }

//                 for(int j=0; j<arr[last].size(); j++){
//                     l.push_back(arr[last][j]);
//                     togo.push(l);
//                 }
//             }
//         }

//         // for(int i=0; i<n; i++){
//         //     cout << brr[i] << ' ';
//         // }
//         // cout << endl;

//         vector < int > went(n, 0);
//         int ans = 0;
//         int max_y = 0;
//         int y_tmp;
//         for(int i=0; i<n; i++){
//             went[i] = 1;
//             y_tmp = dfs(arr, went, i);
//             went[i] = 0;
//             if(y_tmp > max_y){
//                 max_y = y_tmp;
//                 ans = i + 1;
//             }
//         }

//         cout << "Case " << case_t+1 << ": " << ans << endl;
//     }
// }