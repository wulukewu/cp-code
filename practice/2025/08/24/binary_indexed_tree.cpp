#include <bits/stdc++.h>
using namespace std;

const int INF = 2e5;
vector < int > bit(INF, 0);

int lb(int x){
    return x & -x;
}

int add(int x, int y){
    for(int i=x; i<INF; i+=lb(i)){
        bit[i] += y;
    }
}

int sum(int x){
    int res = 0;
    for(int i=x; i>0; i-=lb(i)){
        res += bit[i];
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        add(i+1, x);
    }

    for(int i=0; i<=n; i++){
        cout << bit[i] << ' ';
    }
    cout << endl;

    int m;
    cin >> m;

    int q, a, b;
    for(int i=0; i<m; i++){
        cin >> q >> a >> b;
        if(q==1){
            add(a, b);
        }else{
            cout << sum(b) - sum(a-1) << endl;
        }
    }
}