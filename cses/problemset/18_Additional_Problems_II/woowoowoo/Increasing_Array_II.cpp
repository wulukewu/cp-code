#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
typedef long long ll;

int N, x;
priority_queue<int> Q;

int main(){
    scanf("%d", &N);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        Q.push(x);
        ans += Q.top() - x;
        Q.pop();
        Q.push(x);
    }
    printf("%lld\n", ans);
}
