#include <bits/stdc++.h>
// #define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
template <typename T>
void printQ(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int M=1e9+7;
signed main(){
	Fio;
	int n,m;
	cin>>n>>m;
	vector<int>arr(n),brr(n);
	FOR(i,0,n) cin>>arr[i];
	FOR(i,0,n) cin>>brr[i];

	vector<int>dp(m+1,0);
	FOR(j,0,n){
		FOR(i,0,m+1-arr[j]){
			dp[m-i]=max(dp[m-i],dp[m-i-arr[j]]+brr[j]);
		}
	}
	// print(dp);
	int ans=0;
	FOR(i,0,m+1) ans=max(ans,dp[i]);
	cout<<ans;

}