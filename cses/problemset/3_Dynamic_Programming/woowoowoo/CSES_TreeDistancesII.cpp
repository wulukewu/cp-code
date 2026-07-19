#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

signed main(){
	int n,a,b;
	cin>>n;
	vector<vector<int>>arr(n+1);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	vector<int>v(n+1,0);
	vector<int>ans(n+1,0);
	
	int res=0;
	auto dfs=[&](auto&& self,int x,int p,int o,int cnt)->int{
		int r=0;
		if(o && x!=1){
			ans[x]=ans[p]-v[x]+(n-v[x]-1)-1;
		}
		for(auto& i:arr[x]){
			if(i==p) continue;
			r+=self(self,i,x,o,cnt+1);
		}
		if(o-1){
			v[x]=r;
			res+=cnt;
		}
		return r+1;
	};

	dfs(dfs,1,-1,0,0);
	ans[1]=res;
	dfs(dfs,1,-1,1,0);

	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';

}