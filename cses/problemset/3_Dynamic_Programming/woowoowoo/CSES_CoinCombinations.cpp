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
	int M=1e9+7;
	cin>>n>>m;
	vector<int>arr(n,0);
	FOR(i,0,n) cin>>arr[i];
	vector<int>dp(m+1,0);
	dp[0]=0;
	FOR(i,1,m+1){
		FOR(j,0,n){
			if(i-arr[j]>=0) {
				if(i-arr[j]!=0 and dp[i-arr[j]]>0) 
					dp[i]+=dp[i-arr[j]];
				else if(i-arr[j]==0)dp[i]+=dp[i-arr[j]]+1;
			}
			dp[i]%=M;
		}
	}
	cout<<dp[m];
	// print(dp);
}