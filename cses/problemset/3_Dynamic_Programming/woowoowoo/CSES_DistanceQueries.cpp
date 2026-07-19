#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	int n,q,a,b;
	cin>>n>>q;
	vector<vector<int>>bl(21,vector<int>(n+1,0));
	vector<vector<int>>arr(n+1);
	vector<int>h(n+1,0);
	for(int i=1;i<n;i++) {
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}

	bl[0][1]=1;

	auto dfs=[&](auto &&self,int x,int p,int cnt)->void{
		h[x]=cnt;
		for(auto& i:arr[x]){
			if(i==p) continue;
			bl[0][i]=x;
			self(self,i,x,cnt+1);
		}
	};

	dfs(dfs,1,-1,0);

	for(int i=0;i<21;i++){
		for(int j=1;j<=n;j++){
			if(bl[i][j]<=1) continue;
			bl[i+1][j]=bl[i][bl[i][j]];
		}
	}

	auto LCA=[&](int a,int b)->int{
		if(a==b) return a;
		int x,y;
		if(h[a]<=h[b]) {x=a;y=b;}
		else {y=a;x=b;}
		int l=h[y]-h[x];

		for(int i=0;i<21;i++) if((l>>i)&1) y=bl[i][y];

		if(x==y) return x;

		for(int i=20;i>=0;i--){
			if(bl[i][x]!=bl[i][y]){
				x=bl[i][x];
				y=bl[i][y];
			}
		}
		return bl[0][x];
	};

	for(int i=0;i<q;i++){
		cin>>a>>b;
		int t=LCA(a,b);
		cout<<h[a]+h[b]-2*h[t]<<endl;;
	}

}