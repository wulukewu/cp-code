#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    cout << "哈哈這我沒寫出來\n";
    int big1 = -1 , big2 = -1 , bigi = -1 , bigc = 0 , small1 = -1 , small2 = -1 , smalli = -1 , smallc = 0;
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        num[i] = t;
        if(big1 == -1){
            big1 = t;
            bigi = i;
        }
        else if(big1 < t){
            big1 = t;
            bigi = i;
            big2 = big1;
            bigc = 0;
        }
        else if (big2 != -1 && t < big2){
            bigc++;
        }
    }
    int ans = n*n , ansb = (n-bigi) * (n-bigi);
    if(bigc == 0){
        int a = big1,b;
        for(int i=0;i<bigi;i++){
            b = num[i];
            if(a > b){
                ansb += (bigi + bigc) * (bigi + bigc);
                break;
            }
            a = b;
        }
    }
    ans = min(ans,ansb);
    for(int i=n-1;i>=0;i--){
        int t = num[i];
        if(small1 == -1){
            small1 = t;
            smalli = i;
        }
        else if(small1 > t){
            small1 = t;
            smalli = i;
            small2 = small1;
            smallc = 0;
        }
        else if(small2 != -1 && t > small2){
            smallc++;
        }
    }
    int anss = (smalli+1) * (smalli+1);
    if(smallc == 0){
        int a = small1,b;
        for(int i=n-1;i>smalli;i--){
            b = num[i];
            if(a < b){
                anss += (n-smalli+smallc) * (n-smalli+smallc);
            }
        }
    }
    ans = min(ans,anss);
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}