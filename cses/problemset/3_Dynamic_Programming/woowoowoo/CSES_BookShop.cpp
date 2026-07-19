#include <bits/stdc++.h>
// #define int long long
#define FOR(i,a,b) for(i=a;i<b;i++)
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
	int n,x;
	register int i,j;
	cin>>n>>x;
	vector<int>B(n);
	vector<int>P(n);
	FOR(i,0,n) cin>>P[i];
	FOR(i,0,n) cin>>B[i];
	vector<int>dp(x+1,0);
	vector<vector<bool>>ddp(x+1,vector<bool>(n,0));
	// dp[0]=0;
	FOR(i,1,x+1){
		int y=-1;
		FOR(j,0,n){
			int z=i-P[j];
			if(z<0) continue;
			if(ddp[z][j])continue;
			if(dp[z]+B[j]>dp[i]){
				dp[i]=dp[z]+B[j];
				y=j;
			}
		}
		if(y<0) continue;
		if(i-P[y]>x or i-P[y]<0) continue;
		// FOR(j,0,n) if(ddp[i-P[y]][j]==1) ddp[i][j]=1;
		ddp[i]=ddp[i-P[y]];
		ddp[i][y]=true;
	}
	// FOR(i,0,x+1) print(ddp[i]);
	int M=0;
	// print(dp);
	FOR(i,1,x+1) M=max(M,dp[i]);
	cout<<M;
}