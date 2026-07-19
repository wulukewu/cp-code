#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define Fio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
template<typename T>
void print(T a){
	for(auto u:a){
		cout<<u<<' ';
	}
	cout<<endl;
}
signed main(){
	Fio;
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	FOR(i,0,n) cin>>arr[i];
	vector<int>dp(m+1,m+1);
	dp[0]=0;
	FOR(i,1,m+1){
		FOR(j,0,n){
			if(i-arr[j]>=0) dp[i]=min(dp[i],dp[i-arr[j]]+1);
		}
	}
	// print(dp);
	if(dp[m]>=m+1) cout<<-1;
	else cout<<dp[m];
	

}