// cp
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define endl '\n'
#define sz size
#define Fio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;

int M=1e9+7;
int dp[(1<<20)][20]={0};
vector<int>arr[21];

signed main(){
	Fio;
	int n,m,a,b;
	cin>>n>>m;
	
	FOR(i,0,m){
		cin>>a>>b;
		a--,b--;
		if(a==b) continue;
		arr[a].pb(b);
	}
	
	dp[1][0]=1;

	FOR(i,1,1<<n){
		FOR(j,0,n){
			if(dp[i][j]==0) continue;
			if(j==n-1 && i!=(1<<n)-1) continue;
			for(int& k:arr[j]){
				if(i&(1<<k)) continue;
				dp[i+(1<<k)][k]=(dp[i][j]+dp[i+(1<<k)][k])%M;
			}
		}
	}

	cout<<dp[(1<<n)-1][n-1];
}